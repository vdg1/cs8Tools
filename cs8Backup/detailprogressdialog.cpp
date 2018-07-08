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

#include "detailprogressdialog.h"



DetailProgressDialog::DetailProgressDialog(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    //ctor
}

DetailProgressDialog::~DetailProgressDialog()
{
    //dtor
}

void DetailProgressDialog::setTotalMaximum(int maximum)
{
    ui.pbTotal->setMaximum(maximum);
}

void DetailProgressDialog::setTotalMinimum(int minimum)
{
    ui.pbTotal->setMinimum(minimum);
}

void DetailProgressDialog::setTotalValue(int value)
{
    ui.pbTotal->setValue(value);
}


void DetailProgressDialog::setTotalText(const QString &text)
{
    ui.lbTotal->setText(text);
}

void DetailProgressDialog::setDetailText(const QString &text)
{
    ui.lbDetail->setText(text);
}

void DetailProgressDialog::setDetailProgress(int value, int maximum, int /*rate*/)
{
    ui.pbDetail->setMaximum(maximum);
    ui.pbDetail->setValue(value);
}
