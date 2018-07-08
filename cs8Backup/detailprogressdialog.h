/**************************************************************************
 *   Copyright (C) 2006 by Volker Drewer-Gutland                           *
 *   volker.drewer@gmx.de                                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef DETAILPROGRESSDIALOG_H
#define DETAILPROGRESSDIALOG_H

#include <QDialog>

#include "ui_detailProgressDialog.h"

class DetailProgressDialog : public QDialog {
  Q_OBJECT

 public:
  DetailProgressDialog(QWidget *parent = 0);
  virtual ~DetailProgressDialog();
  void setTotalMaximum(int maximum);
  void setTotalMinimum(int minimum);
  void setTotalValue(int value);
  void setTotalText(const QString &text);
  void setDetailText(const QString &text);
  void setDetailProgress(int value, int maximum, int);

 protected:
 private:
  Ui::DetailProgressDialog ui;
};

#endif  // DETAILPROGRESSDIALOG_H
