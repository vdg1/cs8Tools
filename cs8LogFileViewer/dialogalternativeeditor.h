#ifndef DIALOGALTERNATIVEEDITOR_H
#define DIALOGALTERNATIVEEDITOR_H

#include <QDialog>

namespace Ui {
class DialogAlternativeEditor;
}

class DialogAlternativeEditor : public QDialog
{
Q_OBJECT

public:
explicit DialogAlternativeEditor(QWidget *parent = 0, const QString &fileName="");
~DialogAlternativeEditor();

private slots:

void on_leEditorFilePath_textChanged(const QString &arg1);

void on_buttonBox_accepted();

void on_pbSelect_clicked();

void on_buttonBox_rejected();

private:
Ui::DialogAlternativeEditor *ui;
QString m_fileName;
};

#endif // DIALOGALTERNATIVEEDITOR_H
