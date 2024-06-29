#include "choose.h"
#include "ui_choose.h"
#include <QLabel>
#include <QPixmap>
choose::choose(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::choose)
{
    ui->setupUi(this);
}

choose::~choose()
{
    delete ui;
}
void choose::put_picture()
{
    QPixmap pixmap(":/image/images/cho.png");
    ui->label->clear();
    ui->label->setScaledContents(true);
    ui->label->setPixmap(pixmap);
    ui->label->show();
}

void choose::on_pushButton_clicked()
{
    emit write_signals();
    emit close_signals();
}


void choose::on_pushButton_2_clicked()
{
    emit backsee_signals();
    emit close_signals();
}

