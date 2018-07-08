#include "dialoghighlightconfiguration.h"
#include "ui_dialoghighlightconfiguration.h"
#include <QDataWidgetMapper>
#include <QDebug>
#include <QMessageBox>

DialogHighLightConfiguration::DialogHighLightConfiguration(QWidget *parent)
    : QDialog(parent), m_modified(false),
      ui(new Ui::DialogHighLightConfiguration), m_model(nullptr) {
  ui->setupUi(this);
  mapper = new QDataWidgetMapper(this);
  mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
}

DialogHighLightConfiguration::~DialogHighLightConfiguration() { delete ui; }

void DialogHighLightConfiguration::setItemList(highlightItemList *list) {
  ui->listView->setModel(list);
  m_model = list;
  mapper->setModel(list);
  mapper->addMapping(ui->leSearchString, 8);
  mapper->addMapping(ui->lbBackgroundColor, 1, "color");
  mapper->addMapping(ui->lbForegroundColor, 2, "color");
  mapper->addMapping(ui->cbBold, 3);
  mapper->addMapping(ui->cbIgnoreCase, 4);
  mapper->addMapping(ui->cbItalic, 5);
  mapper->addMapping(ui->cbHighLight, 6);
  mapper->addMapping(ui->cbLevel, 7, "currentIndex");
  mapper->addMapping(ui->cbRegExp, 9);
  mapper->toFirst();
  mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
  connect(ui->listView->selectionModel(),
          &QItemSelectionModel::currentRowChanged, this,
          &DialogHighLightConfiguration::slotRowChanged);
  connect(list, &highlightItemList::dataChanged, this,
          &DialogHighLightConfiguration::slotDataChanged);
  connect(list, &highlightItemList::itemChanged, this,
          &DialogHighLightConfiguration::slotItemChanged);
}

bool DialogHighLightConfiguration::modified() const { return m_modified; }

void DialogHighLightConfiguration::on_pbAddItem_clicked() {
  if (ui->listView->model() == nullptr)
    return;
  highlightItemList *model =
      qobject_cast<highlightItemList *>(ui->listView->model());
  int row = ui->listView->currentIndex().row();
  if (row == -1)
    row = model->rowCount();
  model->addRule(row, QStringLiteral("String Match"), false,
                 QColor(Qt::white).name(), QColor(Qt::black).name(), false,
                 false, false, false, cs8LogFileData::Anything);
  QModelIndex index = model->index(row, 0);
  ui->listView->setCurrentIndex(index);
  ui->leSearchString->selectAll();
  ui->leSearchString->setFocus();
  /*
   *model->insertRow(row);
  model->setData(model->index(row,0),"String Match");
  model->setData(model->index(row,1),Qt::white);
  model->setData(model->index(row,2),Qt::black);
  model->setData(model->index(row,3),false);
  model->setData(model->index(row,4),false);
  model->setData(model->index(row,5),false);
  */

  // ui->listView->selectionModel()->select();
}

highlightItemList::highlightItemList(QObject *parent)
    : QStandardItemModel(parent) {
  setColumnCount(10);
}

void highlightItemList::addRule(int row, const QString &searchText,
                                bool searchIsRegexp, const QString &background,
                                const QString &foreground, bool bold,
                                bool italic, bool ignoreCase, bool highLight,
                                cs8LogFileData::MessageLevel level) {
  insertRow(row);
  setData(index(row, 0), searchText);
  setData(index(row, 8), searchText);
  setData(index(row, 1), background);
  setData(index(row, 2), foreground);
  setData(index(row, 3), bold);
  setData(index(row, 4), ignoreCase);
  setData(index(row, 5), italic);
  setData(index(row, 6), highLight);
  setData(index(row, 7), level);
  setData(index(row, 9), searchIsRegexp);
  QBrush brush;
  brush.setColor(background);
  setData(index(row, 0), brush, Qt::BackgroundRole);
  brush.setColor(foreground);
  setData(index(row, 0), brush, Qt::ForegroundRole);
  QFont font;
  font.setBold(bold);
  font.setItalic(italic);
  setData(index(row, 0), font, Qt::FontRole);
}

/*
void highlightItemList::addRule(int row, const QString &text, const QColor
&background, const QColor foreground, bool bold, bool italic, bool
caseSensitive)
{
    addRule(row,
text,background.name(),foreground.name(),bold,italic,caseSensitive,true);
}
*/

QString highlightItemList::searchString(int row) const {
  QModelIndex idx = index(row, 8);
  if (!idx.isValid())
    return QString();
  return data(idx).toString();
}

QString highlightItemList::foregroundColor(int row) const {
  QModelIndex idx = index(row, 2);
  if (!idx.isValid())
    return QString();
  return data(idx).toString();
}

QString highlightItemList::backgroundColor(int row) const {
  QModelIndex idx = index(row, 1);
  if (!idx.isValid())
    return QString();
  return data(idx).toString();
}

bool highlightItemList::italic(int row) const {
  QModelIndex idx = index(row, 5);
  if (!idx.isValid())
    return false;
  return data(idx).toBool();
}

bool highlightItemList::bold(int row) const {
  QModelIndex idx = index(row, 3);
  if (!idx.isValid())
    return false;
  return data(idx).toBool();
}

bool highlightItemList::ignoreCase(int row) const {
  QModelIndex idx = index(row, 4);
  if (!idx.isValid())
    return false;
  return data(idx).toBool();
}

bool highlightItemList::highlightInScrollbar(int row) const {
  QModelIndex idx = index(row, 6);
  if (!idx.isValid())
    return false;
  return data(idx).toBool();
}

bool highlightItemList::isRegularExpression(int row) const {
  QModelIndex idx = index(row, 9);
  if (!idx.isValid())
    return false;
  return data(idx).toBool();
}

cs8LogFileData::MessageLevel highlightItemList::level(int row) const {
  QModelIndex idx = index(row, 7);
  if (!idx.isValid())
    return cs8LogFileData::Anything;
  // qDebug() << "level() " << data(idx);
  return static_cast<cs8LogFileData::MessageLevel>(data(idx).toInt());
}

void DialogHighLightConfiguration::on_pdRemoveItem_clicked() {
  int row = ui->listView->currentIndex().row();
  if (row != -1) {
    if (QMessageBox::question(
            this, tr("Remove highlight rule"),
            tr("Are you sure you want to delete the highlight rule?"),
            QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
      ui->listView->model()->removeRows(row, 1);
  }
}

void DialogHighLightConfiguration::on_pdMoveUp_clicked() {
  int row = ui->listView->currentIndex().row();
  if (row > 0) {
    int newRow = row - 1;
    ui->listView->model()->insertRow(newRow);
    row++;
    for (int i = 0; i < ui->listView->model()->columnCount(); i++) {
      ui->listView->model()->setData(
          ui->listView->model()->index(newRow, i),
          ui->listView->model()->data(ui->listView->model()->index(row, i)));
    }
    ui->listView->setCurrentIndex(ui->listView->model()->index(newRow, 0));
    ui->listView->model()->removeRow(row);
  }
}

void DialogHighLightConfiguration::slotRowChanged(QModelIndex index) {
  mapper->setCurrentModelIndex(index);
  qDebug() << "New row selected: " << index.row()
           << " level: " << m_model->level(index.row());
  ui->groupBox->setEnabled(index.isValid());
  // QModelIndex idx = ui->listView->model()->index(index.row(), 7);
  // ui->leSearchString->setEnabled(ui->listView->model()->data(idx)==0);
}

void DialogHighLightConfiguration::slotDataChanged(QModelIndex from,
                                                   QModelIndex /*to*/) {
  // qDebug() << "data changed:"  << from;
  m_modified = true;
  if (from.column() > 0) {
    int row = from.row();
    QBrush brush;
    QColor color(m_model->backgroundColor(row));
    brush.setColor(color);
    ui->listView->model()->setData(ui->listView->model()->index(from.row(), 0),
                                   brush, Qt::BackgroundRole);

    QColor col(m_model->foregroundColor(row));
    brush.setColor(col);
    ui->listView->model()->setData(ui->listView->model()->index(from.row(), 0),
                                   brush, Qt::ForegroundRole);

    QFont font;
    font.setBold(m_model->bold(row));
    font.setItalic(m_model->italic(row));

    ui->listView->model()->setData(ui->listView->model()->index(from.row(), 0),
                                   font, Qt::FontRole);
    qDebug() << "level: " << m_model->level(row)
             << " string: " << m_model->searchString(row);
    if (m_model->level(row) != 0 && m_model->searchString(row).isEmpty()) {
      ui->listView->model()->setData(
          ui->listView->model()->index(from.row(), 0),
          QStringLiteral("[%1]").arg(
              cs8LogFileData::levelNames.at(m_model->level(row))),
          Qt::DisplayRole);
    } else if (m_model->level(row) == 0) {
      ui->listView->model()->setData(
          ui->listView->model()->index(from.row(), 0),
          m_model->searchString(row), Qt::DisplayRole);
    } else {
      ui->listView->model()->setData(
          ui->listView->model()->index(from.row(), 0),
          m_model->searchString(row), Qt::DisplayRole);
    }
    m_modified = true;
  }
}

void DialogHighLightConfiguration::slotItemChanged(QStandardItem *item) {
  qDebug() << "item changed: " << item->index();
}

void DialogHighLightConfiguration::on_pbSubmit_clicked() { mapper->submit(); }

void DialogHighLightConfiguration::on_cbBold_clicked() { mapper->submit(); }

void DialogHighLightConfiguration::on_cbItalic_clicked() { mapper->submit(); }

void DialogHighLightConfiguration::on_lbForegroundColor_textChanged(
    const QString & /*arg1*/) {
  mapper->submit();
}

void DialogHighLightConfiguration::on_lbBackgroundColor_textChanged(
    const QString & /*arg1*/) {
  mapper->submit();
}

void DialogHighLightConfiguration::on_pdMoveDown_clicked() {
  int row = ui->listView->currentIndex().row();
  if (row < ui->listView->model()->rowCount() - 1) {
    int newRow = row + 2;
    ui->listView->model()->insertRow(newRow);
    // row;
    for (int i = 0; i < ui->listView->model()->columnCount(); i++) {
      ui->listView->model()->setData(
          ui->listView->model()->index(newRow, i),
          ui->listView->model()->data(ui->listView->model()->index(row, i)));
    }
    ui->listView->setCurrentIndex(ui->listView->model()->index(newRow, 0));
    ui->listView->model()->removeRow(row);
  }
}

void DialogHighLightConfiguration::on_cbLevel_currentIndexChanged(
    int /*index*/) {
  mapper->submit();
}
