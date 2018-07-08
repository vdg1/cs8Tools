#include <QSettings>
#include <QDir>
#include <QFileDialog>
#include <QTranslator>
#include <QDateTime>

#include "settingsdialog.h"

settingsDialog::settingsDialog(QWidget *parent, int page) : QDialog(parent)
{
    ui.setupUi(this);

    QSettings settings;
    ui.lineEditDownLoadDir->setText(QDir::toNativeSeparators( settings.value( "directories/downloadDir", m_defaultDir ).toString()));

    ui.cbSys->setChecked(settings.value("defaultSys", true).toBool());
    ui.cbUsr->setChecked(settings.value("defaultUsr", true).toBool());
    ui.cbLog->setChecked(settings.value("defaultLog", true).toBool());
    ui.cbCompress->setChecked(settings.value("defaultCompress", true).toBool());
    ui.cbPreserveTimeStamp->setChecked(settings.value("preserveTimeStamp", true).toBool());
    ui.leBackupTemplate->setText(settings.value("backupNameTemplate", "_%SN").toString());
    ui.spAutomaticRetries->setValue(settings.value("automaticRetries", 5).toInt());

    // fill language combobox
    ui.cbLanguages->addItem(tr("English"));

    foreach(QString language, findQmFiles())
    {
        QTranslator translator;
        translator.load(language);
        ui.cbLanguages->addItem(translator.translate("settingsDialog", "English"));
        QVariant data = language;
        ui.cbLanguages->setItemData(ui.cbLanguages->count() - 1, data);
        if (language == settings.value("lang").toString())
            ui.cbLanguages->setCurrentIndex(ui.cbLanguages->count() - 1);
    }
    ui.stackedWidget->setCurrentIndex(page);
}

settingsDialog::~settingsDialog()
{
    //dtor
}

void settingsDialog::setDefaultDir(const QString &dir)
{
    m_defaultDir = dir;
    ui.lineEditDownLoadDir->setText(m_defaultDir);
}

void settingsDialog::on_dirButton_clicked()
{
    ui.lineEditDownLoadDir->setText(QFileDialog::getExistingDirectory(
                        this,
                        tr("Choose a directory where you want to store the downloaded backup:"),
                        ui.lineEditDownLoadDir->text(), QFileDialog::ShowDirsOnly
                        | QFileDialog::DontResolveSymlinks));
}

void settingsDialog::on_okButton_clicked()
{
    QSettings settings;
    settings.setValue("directories/downloadDir", ui.lineEditDownLoadDir->text());
    settings.setValue("lang", ui.cbLanguages->itemData(ui.cbLanguages->currentIndex(), Qt::UserRole).toString());
    settings.setValue("defaultSys", ui.cbSys->isChecked());
    settings.setValue("defaultLog", ui.cbUsr->isChecked());
    settings.setValue("defaultUsr", ui.cbLog->isChecked());
    settings.setValue("defaultCompress", ui.cbCompress->isChecked());
    settings.setValue("backupNameTemplate", ui.leBackupTemplate->text());
    settings.setValue("preserveTimeStamp", ui.cbPreserveTimeStamp->isChecked());
    settings.setValue("automaticRetries", ui.spAutomaticRetries->value());
}

QStringList settingsDialog::findQmFiles()
{
    QDir dir(":/translations");
    QStringList fileNames = dir.entryList(QStringList("*.qm"), QDir::Files,
                                          QDir::Name);
    QMutableStringListIterator i(fileNames);
    while (i.hasNext())
    {
        i.next();
        i.setValue(dir.filePath(i.value()));
    }
    return fileNames;
}

void settingsDialog::on_leBackupTemplate_textChanged(const QString /*&arg1*/)
{
    QString name = ui.leBackupTemplate->text();
    name.replace("%SN", "F06_123A1_C_01");
    name = QDateTime::currentDateTime().toString("yyyyMMdd-hhmm") + name;
    ui.lbExample->setText(name);
}
