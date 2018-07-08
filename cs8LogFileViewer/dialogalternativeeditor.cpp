#include "dialogalternativeeditor.h"
#include "ui_dialogalternativeeditor.h"



#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QtWin>
#include <QImage>
#include <QPixmap>
#include <QSettings>
#include <QDebug>
#include <QFileDialog>
#include <QProcess>

#include <iostream>

#include <shellapi.h>
#include <comdef.h>
#include <commctrl.h>
#include <objbase.h>
#include <commoncontrols.h>

struct PixmapEntry {
    QString name;
    QPixmap pixmap;
};

typedef QList<PixmapEntry> PixmapEntryList;

static QString formatSize(const QSize &size)
{
    return QString::number(size.width()) + QLatin1Char('x') + QString::number(size.height());
}

// Helper for extracting large/jumbo icons available from Windows Vista onwards
// via SHGetImageList().
static QPixmap pixmapFromShellImageList(int iImageList, const SHFILEINFO &info)
{
    QPixmap result;
    // For MinGW:
    static const IID iID_IImageList = {0x46eb5926, 0x582e, 0x4017, {0x9f, 0xdf, 0xe8, 0x99, 0x8d, 0xaa, 0x9, 0x50}};

    IImageList *imageList = Q_NULLPTR;
    if (FAILED(SHGetImageList(iImageList, iID_IImageList, reinterpret_cast<void **>(&imageList))))
        return result;

    HICON hIcon = 0;
    if (SUCCEEDED(imageList->GetIcon(info.iIcon, ILD_TRANSPARENT, &hIcon))) {
        result = QtWin::fromHICON(hIcon);
        DestroyIcon(hIcon);
    }
    return result;
}

static PixmapEntryList extractShellIcons(const QString &sourceFile, bool addOverlays)
{
    enum { // Shell image list ids
        sHIL_EXTRALARGE = 0x2, // 48x48 or user-defined
        sHIL_JUMBO = 0x4 // 256x256 (Vista or later)
    };

    struct FlagEntry {
        const char *name;
        unsigned flags;
    };

    const FlagEntry modeEntries[] =
    {
        {"",     0},
        {"open", SHGFI_OPENICON},
        {"sel",  SHGFI_SELECTED},
    };
    const FlagEntry standardSizeEntries[] =
    {
        {"s",  SHGFI_SMALLICON},
        {"l",  SHGFI_LARGEICON},
        {"sh", SHGFI_SHELLICONSIZE},
    };

    const QString nativeName = QDir::toNativeSeparators(sourceFile);
    const wchar_t *sourceFileC = reinterpret_cast<const wchar_t *>(nativeName.utf16());

    SHFILEINFO info;
    unsigned int baseFlags = SHGFI_ICON | SHGFI_SYSICONINDEX | SHGFI_ICONLOCATION;
    if (addOverlays)
        baseFlags |= SHGFI_ADDOVERLAYS | SHGFI_OVERLAYINDEX;
    if (!QFileInfo(sourceFile).isDir())
        baseFlags |= SHGFI_USEFILEATTRIBUTES;

    const size_t modeEntryCount = sizeof(modeEntries) / sizeof(modeEntries[0]);
    const size_t standardSizeEntryCount = sizeof(standardSizeEntries) / sizeof(standardSizeEntries[0]);
    PixmapEntryList result;
    for (size_t m = 0; m < modeEntryCount; ++m) {
        const unsigned modeFlags = baseFlags | modeEntries[m].flags;
        QString modePrefix = QLatin1String("_shell_");
        if (modeEntries[m].name[0])
            modePrefix += QLatin1String(modeEntries[m].name) + QLatin1Char('_');
        for (size_t s = 0; s < standardSizeEntryCount; ++s) {
            const unsigned flags = modeFlags | standardSizeEntries[s].flags;
            const QString prefix = modePrefix + QLatin1String(standardSizeEntries[s].name)
                                   + QLatin1Char('_');
            ZeroMemory(&info, sizeof(SHFILEINFO));
            const HRESULT hr = SHGetFileInfo(sourceFileC, 0, &info, sizeof(SHFILEINFO), flags);
            if (FAILED(hr)) {
                //_com_error error(hr);
                //std::wcerr << "SHGetFileInfo() failed for \"" << nativeName << "\", "
                //           << std::hex << std::showbase << flags << std::dec << std::noshowbase
                //           << " (" << prefix << "): " << error.ErrorMessage() << '\n';
                continue;
            }

            if (info.hIcon) {
                PixmapEntry entry;
                entry.pixmap = QtWin::fromHICON(info.hIcon);
                DestroyIcon(info.hIcon);
                if (entry.pixmap.isNull()) {
                    std::wcerr << "Error converting icons.\n";
                    return PixmapEntryList();
                }
                entry.name = prefix + formatSize(entry.pixmap.size());

                const int iconIndex = info.iIcon & 0xFFFFFF;
                const int overlayIconIndex = info.iIcon >> 24;

                std::wcout << "Obtained icon #" << iconIndex;
                if (addOverlays)
                    std::wcout << " (overlay #" << overlayIconIndex << ')';
                //if (info.szDisplayName[0])
                //    std::wcout << " from " << QString::fromWCharArray(info.szDisplayName);
                std::wcout << " (" << entry.pixmap.width() << 'x'
                           << entry.pixmap.height() << ") for " << std::hex << std::showbase << flags
                           << std::dec << std::noshowbase << '\n';

                result.append(entry);
            }
        } // for standardSizeEntryCount
          // Windows Vista onwards: extract large/jumbo icons
        if (QSysInfo::windowsVersion() >= QSysInfo::WV_VISTA && info.hIcon) {
            const QPixmap extraLarge = pixmapFromShellImageList(sHIL_EXTRALARGE, info);
            if (!extraLarge.isNull()) {
                PixmapEntry entry;
                entry.pixmap = extraLarge;
                entry.name = modePrefix + QLatin1String("xl_") + formatSize(extraLarge.size());
                result.append(entry);
            }
            const QPixmap jumbo = pixmapFromShellImageList(sHIL_JUMBO, info);
            if (!jumbo.isNull()) {
                PixmapEntry entry;
                entry.pixmap = jumbo;
                entry.name = modePrefix + QLatin1String("jumbo_") + formatSize(extraLarge.size());
                result.append(entry);
            }
        }
    } // for modes
    return result;
}


DialogAlternativeEditor::DialogAlternativeEditor(QWidget *parent, const QString & fileName) :
    QDialog(parent), m_fileName(fileName),
    ui(new Ui::DialogAlternativeEditor)
{
    ui->setupUi(this);
    QString txt=ui->label->text();
    ui->label->setText(txt.arg(fileName));

    QSettings settings;
    ui->leEditorFilePath->setText(settings.value("alternativeEditor",QLatin1Literal("C:\\Windows\\System32\\notepad.exe")).toString());
}

DialogAlternativeEditor::~DialogAlternativeEditor()
{
    delete ui;
}


void DialogAlternativeEditor::on_leEditorFilePath_textChanged(const QString &arg1)
{
    QString fileName=arg1;
    QFileInfo info(fileName);
    qDebug() << "Editor " << fileName << " exists: " << info.exists() << " suffix: " << info.suffix();
    if (info.exists() && (info.suffix()==QLatin1Literal("exe")))
    {
        // set icon in dialog
        ui->labelIcon->setPixmap(extractShellIcons(arg1,false).at(0).pixmap);
        ui->buttonBox->button(QDialogButtonBox::Yes)->setEnabled(true);
    }
    else
    {
        ui->buttonBox->button(QDialogButtonBox::Yes)->setEnabled(false);
    }
}

void DialogAlternativeEditor::on_buttonBox_accepted()
{
    QProcess::startDetached(ui->leEditorFilePath->text(), QStringList() << QDir::toNativeSeparators(m_fileName));
    accept();
}

void DialogAlternativeEditor::on_pbSelect_clicked()
{
    QString f;
    f=QFileDialog::getOpenFileName(this,
                                   tr("Select Editor"),
                                   ui->leEditorFilePath->text(),
                                   tr("Executables (*.exe)"),
                                   Q_NULLPTR,
                                   QFileDialog::ReadOnly);
    if (!f.isEmpty())
    {
        ui->leEditorFilePath->setText(f);
        QSettings settings;
        settings.setValue("alternativeEditor",f);

    }
}

void DialogAlternativeEditor::on_buttonBox_rejected()
{
    reject();
}
