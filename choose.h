#ifndef CHOOSE_H
#define CHOOSE_H

#include <QDialog>

namespace Ui {
class choose;
}

class choose : public QDialog
{
    Q_OBJECT

public:
    explicit choose(QWidget *parent = nullptr);
    ~choose();
    void put_picture();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::choose *ui;

signals:
    void write_signals();
    void close_signals();
    void backsee_signals();
};

#endif // CHOOSE_H
