#ifndef CS8ANNOTATIONEDITOR_H
#define CS8ANNOTATIONEDITOR_H

#include <QDialog>

namespace Ui {
class cs8AnnotationEditor;
}

class cs8AnnotationEditor : public QDialog {
  Q_OBJECT

public:
  explicit cs8AnnotationEditor(QWidget *parent = nullptr);
  void setStartAndEnd(int start, int end);
  int start() const;
  int end() const;
  void setLevel(int level);
  int level() const;

  QString text() const;
  void setText(const QString &text);
  ~cs8AnnotationEditor();

private:
  Ui::cs8AnnotationEditor *ui;
};

#endif // CS8ANNOTATIONEDITOR_H
