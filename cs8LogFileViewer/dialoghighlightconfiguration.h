#ifndef DIALOGHIGHLIGHTCONFIGURATION_H
#define DIALOGHIGHLIGHTCONFIGURATION_H

#include "cs8logfiledata.h"
#include <QDialog>
#include <QStandardItemModel>

class highlightItemList : public QStandardItemModel {
  Q_OBJECT

public:
  explicit highlightItemList(QObject *parent = nullptr);
  void addRule(int row, const QString &searchText, bool searchIsRegexp,
               const QString &background, const QString &foreground, bool bold,
               bool italic, bool caseSensitive, bool highLight,
               cs8LogFileData::MessageLevel level);

  QString searchString(int row) const;
  QString foregroundColor(int row) const;
  QString backgroundColor(int row) const;
  bool italic(int row) const;
  bool bold(int row) const;
  bool ignoreCase(int row) const;
  bool highlightInScrollbar(int row) const;
  bool isRegularExpression(int row) const;
  cs8LogFileData::MessageLevel level(int row) const;
};

class QDataWidgetMapper;

namespace Ui {
class DialogHighLightConfiguration;
}

class DialogHighLightConfiguration : public QDialog {
  Q_OBJECT

public:
  explicit DialogHighLightConfiguration(QWidget *parent = nullptr);
  ~DialogHighLightConfiguration();
  void setItemList(highlightItemList *list);
  bool modified() const;

private slots:
  void on_pbAddItem_clicked();

  void on_pdRemoveItem_clicked();

  void on_pdMoveUp_clicked();

  void slotRowChanged(QModelIndex index);

  void slotDataChanged(QModelIndex from, QModelIndex);

  void slotItemChanged(QStandardItem *item);

  void on_pbSubmit_clicked();

  void on_cbBold_clicked();

  void on_cbItalic_clicked();

  void on_lbForegroundColor_textChanged(const QString &);

  void on_lbBackgroundColor_textChanged(const QString &arg1);

  void on_pdMoveDown_clicked();

  void on_cbLevel_currentIndexChanged(int);

private:
  bool m_modified;
  Ui::DialogHighLightConfiguration *ui;
  QDataWidgetMapper *mapper;
  highlightItemList *m_model;
};

#endif // DIALOGHIGHLIGHTCONFIGURATION_H
