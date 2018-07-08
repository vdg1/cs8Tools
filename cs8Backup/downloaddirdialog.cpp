#include "downloaddirdialog.h"
#include <QFileDialog>

downloadDirDialog::downloadDirDialog(QWidget *parent) :
    QDialog(parent)
{
    ui.setupUi(this);
}

downloadDirDialog::downloadDirDialog(QWidget *parent, const QString &baseDir,
                                     const QString &downloadDir) :
    QDialog(parent)
{
    ui.setupUi(this);
    m_baseDir = baseDir;
    m_downloadDir = downloadDir;
    //ui.lineEditPredefined->setText(baseDir);
    ui.label->setText(ui.label->text().arg(m_baseDir));
    if (m_downloadDir.contains(m_baseDir))
        ui.lineEditUserDefined->setText(QDir::toNativeSeparators(m_downloadDir + "/"));
    else
        ui.lineEditUserDefined->setText(QDir::toNativeSeparators(m_downloadDir + "/" + m_baseDir));
    m_modified = false;
}

downloadDirDialog::~downloadDirDialog()
{

}



void downloadDirDialog::on_toolButtonUserDefined_clicked()
{
    QString directory = ui.lineEditUserDefined->text();
    directory = QFileDialog::getExistingDirectory(this, tr("Select a download directory for %1").arg(m_baseDir), directory);
    if (!directory.isEmpty())
    {
        QDir dir;
        ui.lineEditUserDefined->setText(QDir::toNativeSeparators(dir.absoluteFilePath(directory + "/" + m_baseDir)));
    }
}

void downloadDirDialog::on_lineEditUserDefined_textChanged(const QString &text)
{
    QFileInfo info(text);
    QString path = info.absoluteFilePath();
    m_downloadDir = path.left(path.lastIndexOf("/"));
    m_baseDir = path.right(path.length() - path.lastIndexOf("/") - 1);
    m_modified = true;
}

QString downloadDirDialog::baseDir()
{
    return m_baseDir;
}

