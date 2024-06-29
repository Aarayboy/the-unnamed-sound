#include "backsee.h"
#include "ui_backsee.h"

backsee::backsee(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::backsee)
{
    ui->setupUi(this);
}
QString backsee::savepath = "userdiary.txt";
backsee::~backsee()
{
    delete ui;
}

void backsee::init()
{
    QFile file(savepath);
    file.open(QIODevice::ReadOnly);
    if(file.isOpen())
    {

        while(!file.atEnd())
        {
            QString text = file.readLine();
            ui->textBrowser->append(text);
        }
        file.close();
    }

}
