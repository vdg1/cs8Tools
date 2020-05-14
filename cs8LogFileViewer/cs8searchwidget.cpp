/****************************************************************************
 **
 ** Trolltech hereby grants a license to use the Qt/Eclipse Integration
 ** plug-in (the software contained herein), in binary form, solely for the
 ** purpose of creating code to be used with Trolltech's Qt software.
 **
 ** Qt Designer is licensed under the terms of the GNU General Public
 ** License versions 2.0 and 3.0 ("GPL License"). Trolltech offers users the
 ** right to use certain no GPL licensed software under the terms of its GPL
 ** Exception version 1.2 (http://trolltech.com/products/qt/gplexception).
 **
 ** THIS SOFTWARE IS PROVIDED BY TROLLTECH AND ITS CONTRIBUTORS (IF ANY) "AS
 ** IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 ** TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 ** PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 ** OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 ** EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 ** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 ** PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 ** LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 ** NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 ** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
 **
 ** Since we now have the GPL exception I think that the "special exception
 ** is no longer needed. The license text proposed above (other than the
 ** special exception portion of it) is the BSD license and we have added
 ** the BSD license as a permissible license under the exception.
 **
 ****************************************************************************/

#include "cs8searchwidget.h"

#include <QDebug>
#include <QHeaderView>
#include <QSortFilterProxyModel>
#include <QTimer>

cs8SearchWidget::cs8SearchWidget(QWidget *parent) : QWidget(parent) {
  ui.setupUi(this);

  m_filterProxy = new QSortFilterProxyModel(this);
  m_filterProxy->setFilterKeyColumn(2);

  m_timer = new QTimer(this);
  m_timer->setSingleShot(true);
  m_timer->setInterval(1000);
  connect(m_timer, &QTimer::timeout, this,
          &cs8SearchWidget::updateSearchParameters);
  // connect(ui.listViewResults, SIGNAL(activated(const QModelIndex &)), this,
  // SLOT(slotSearchResultSelected(const QModelIndex &)));
  connect(ui.listViewResults, &QAbstractItemView::doubleClicked, this,
          &cs8SearchWidget::slotSearchResultSelected);
  connect(this, &cs8SearchWidget::searchRegExpValid, this,
          &cs8SearchWidget::slotRegExpValid);

  connect(m_filterProxy, &QSortFilterProxyModel::sourceModelChanged, [=]() {
    updateSearchFilterProxy();
    ui.labelHits->setText(QString("%1").arg(m_filterProxy->rowCount()));
  });
}

cs8SearchWidget::~cs8SearchWidget() {}

void cs8SearchWidget::setModel(logFileModel *model) {
  m_sourceModel = model;
  m_filterProxy->setSourceModel(model);
}

void cs8SearchWidget::on_toolButtonClear_clicked() {
  ui.lineEditSearchText->clear();
}

void cs8SearchWidget::on_lineEditSearchText_textChanged(
    const QString &searchText) {
  if (searchText.isEmpty()) {
    ui.listViewResults->setModel(0);
    ui.labelHits->setText(QString("%1").arg(0));
  } else {
    m_timer->stop();
    m_timer->start();
    m_searchText = searchText;
  }
}

void cs8SearchWidget::updateSearchFilterProxy() {
  if (m_isRegExp) {
    m_filterProxy->setFilterRegExp(m_searchText);
    emit searchRegExpValid(m_filterProxy->filterRegExp().isValid());
  } else {
    m_filterProxy->setFilterFixedString(m_searchText);
    emit searchRegExpValid(true);
  }
  m_filterProxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
}

void cs8SearchWidget::updateSearchParameters() {
  updateSearchFilterProxy();
  ui.labelHits->setText(QString("%1").arg(m_filterProxy->rowCount()));
  ui.listViewResults->resizeColumnsToContents();
  if (ui.listViewResults->model() == 0) {
    ui.listViewResults->setModel(m_filterProxy);
    // ui.listViewResults->hideColumn(0);
    // ui.listViewResults->verticalHeader()->hide();
    for (int i = 0; i < 4; i++) {
      ui.listViewResults->resizeColumnToContents(i);
    }
    for (int i = 0; i < m_filterProxy->rowCount(); i++) {
      QModelIndex proxyIndex = m_filterProxy->index(i, 2);
      QModelIndex index = m_filterProxy->mapToSource(proxyIndex);
      QBrush brush;
      brush.setColor(Qt::red);
      if (!index.isValid())
        qDebug() << "Index not valid";
      if (!m_sourceModel->setData(index, brush, Qt::BackgroundColorRole))
        qDebug() << "Setting data failed";
    }
  }
}

void cs8SearchWidget::slotSearchResultSelected(const QModelIndex &index) {
  QModelIndex i = m_filterProxy->sourceModel()->index(
      m_filterProxy->mapToSource(index).row(), 2);
  int row = i.row();
  qDebug() << "search result selected line: " << row;
  emit lineSelected(row);
}

void cs8SearchWidget::slotRegExpValid(bool valid) {
  if (!valid)
    ui.lineEditSearchText->setStyleSheet("border: 1px solid red");
  else
    ui.lineEditSearchText->setStyleSheet("");
}

bool cs8SearchWidget::isRegExp() const { return m_isRegExp; }

void cs8SearchWidget::setIsRegExp(bool isRegExp) {
  m_isRegExp = isRegExp;
  ui.cbRegularExpression->setChecked(isRegExp);
  updateSearchParameters();
}

QString cs8SearchWidget::searchText() const { return m_searchText; }

void cs8SearchWidget::setSearchText(const QString &searchText) {
  m_searchText = searchText;
  ui.lineEditSearchText->setText(m_searchText);
  updateSearchParameters();
}

void cs8SearchWidget::on_cbRegularExpression_toggled(bool checked) {
  m_isRegExp = checked;
  updateSearchParameters();
}
