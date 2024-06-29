#ifndef CONTENT_H
#define CONTENT_H

#include <QDateTime>
#include <QDialog>
#include <QFile>
#include <QTextStream>
namespace Ui {
class content;
}

class content : public QDialog
{
    Q_OBJECT

public:
    explicit content(QWidget *parent = nullptr);
    ~content();
    static const QString savepath;
signals:
    void close_con_signals();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::content *ui;
};

#endif // CONTENT_H
