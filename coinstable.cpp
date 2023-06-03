#include "coinstable.h"
#include "ui_coinstable.h"
#include "dbmanager.h"
#include "sqlitedbmanager.h"
#include "addcoin.h"

#include <QSqlTableModel>


CoinsTable::CoinsTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CoinsTable)
{
    ui->setupUi(this);
    this->setupModel(COINS_TABLE_NAME,
                     QStringList() << tr("id")
                                   << tr("Країна")
                                   << tr("Номінал")
                                   << tr("Цінність")
                                   << tr("Особливості")
                                   << tr("Рік")
               );
    this->createUI();
}

CoinsTable::~CoinsTable()
{
    delete ui;
}



void CoinsTable::setupModel(const QString &tableName, const QStringList &headers)
{
    DBManager *db = SQLiteDBManager::getInstance();
    model = new QSqlTableModel(this, db->getDB());
    model->setTable(tableName);

    for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    model->setSort(0,Qt::AscendingOrder);
}

void CoinsTable::createUI()
{
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    model->select();
}

void CoinsTable::on_pushButton_clicked()
{
    AddCoin dialog;
    dialog.setModal(true);
    dialog.exec();
}


void CoinsTable::on_pushButton_2_clicked()
{
    model->removeRow(row);
}


void CoinsTable::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

