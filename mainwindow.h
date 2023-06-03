#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QSqlTableModel;
class DBManager;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(DBManager* dbManager, QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    DBManager *db;
    QSqlTableModel  *model;
    MainWindow *w;
private:
    void setupModel(const QString &tableName, const QStringList &headers);
    void createUI();
};
#endif // MAINWINDOW_H
