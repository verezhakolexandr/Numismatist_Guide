#ifndef ADDCOLLECTOR_H
#define ADDCOLLECTOR_H

#include <QDialog>

namespace Ui {
class AddCollector;
}

class AddCollector : public QDialog
{
    Q_OBJECT

public:
    explicit AddCollector(QWidget *parent = nullptr);
    ~AddCollector();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddCollector *ui;
};

#endif // ADDCOLLECTOR_H
