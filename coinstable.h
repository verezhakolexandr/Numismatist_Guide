#ifndef COINSTABLE_H
#define COINSTABLE_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class CoinsTable;
}

class CoinsTable : public QDialog
{
    Q_OBJECT

public:
    explicit CoinsTable(QWidget *parent = nullptr);
    ~CoinsTable();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::CoinsTable *ui;
    QSqlTableModel *model;
    int row;
private:
    void setupModel(const QString &tableName, const QStringList &headers);
    void createUI();
};

#endif // COINSTABLE_H
