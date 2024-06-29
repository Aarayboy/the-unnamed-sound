#ifndef BACKSEE_H
#define BACKSEE_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
namespace Ui {
class backsee;
}

class backsee : public QDialog
{
    Q_OBJECT

public:
    explicit backsee(QWidget *parent = nullptr);
    ~backsee();
    void init();
    static QString savepath;
private:
    Ui::backsee *ui;
};

#endif // BACKSEE_H
