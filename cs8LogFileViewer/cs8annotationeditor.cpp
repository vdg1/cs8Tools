#include "cs8annotationeditor.h"
#include "ui_cs8annotationeditor.h"

cs8AnnotationEditor::cs8AnnotationEditor(QWidget *parent) : QDialog(parent), ui(new Ui::cs8AnnotationEditor) {
  ui->setupUi(this);
}

void cs8AnnotationEditor::setStartAndEnd(int start, int end) {
  ui->sbStart->setValue(start);
  ui->sbEnd->setValue(end);
}

int cs8AnnotationEditor::start() const { return ui->sbStart->value(); }

int cs8AnnotationEditor::end() const { return ui->sbEnd->value(); }

void cs8AnnotationEditor::setLevel(int level) { ui->cbLevel->setCurrentIndex(level); }

int cs8AnnotationEditor::level() const { return ui->cbLevel->currentIndex(); }

QString cs8AnnotationEditor::text() const { return ui->teAnnotation->toHtml(); }

void cs8AnnotationEditor::setText(const QString &text) { ui->teAnnotation->setHtml(text); }

cs8AnnotationEditor::~cs8AnnotationEditor() { delete ui; }
