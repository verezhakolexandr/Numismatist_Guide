#include "coincollectorstable.h"
#include "ui_coincollectorstable.h"
#include "dbmanager.h"
#include "sqlitedbmanager.h"
#include "addcollector.h"

#include <QSqlTableModel>

CoinCollectorsTable::CoinCollectorsTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CoinCollectorsTable)
{
    ui->setupUi(this);
    this->setupModel(COLLECTORS_TABLE_NAME,
                     QStringList() << tr("id")
                                   << tr("Ім'я")
                                   << tr("Країна")
                                   << tr("Кількість раритетних монет")
                                   << tr("Номер телефону")
               );
    this->createUI();
}

CoinCollectorsTable::~CoinCollectorsTable()
{
    delete ui;
}


void CoinCollectorsTable::setupModel(const QString &tableName, const QStringList &headers)
{
    DBManager *db = SQLiteDBManager::getInstance();
    model = new QSqlTableModel(this, db->getDB());
    model->setTable(tableName);

    for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    model->setSort(0,Qt::AscendingOrder);
}

void CoinCollectorsTable::createUI()
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

void CoinCollectorsTable::on_pushButton_clicked()
{
    AddCollector dialog;
    dialog.setModal(true);
    dialog.exec();
}


void CoinCollectorsTable::on_pushButton_2_clicked()
{
    model->removeRow(row);
}


void CoinCollectorsTable::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

