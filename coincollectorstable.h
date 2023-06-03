#ifndef COINCOLLECTORSTABLE_H
#define COINCOLLECTORSTABLE_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class CoinCollectorsTable;
}

class CoinCollectorsTable : public QDialog
{
    Q_OBJECT

public:
    explicit CoinCollectorsTable(QWidget *parent = nullptr);
    ~CoinCollectorsTable();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::CoinCollectorsTable *ui;
    QSqlTableModel *model;
    int row;
private:
    void setupModel(const QString &tableName, const QStringList &headers);
    void createUI();
};

#endif // COINCOLLECTORSTABLE_H
