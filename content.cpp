#include "content.h"
#include "ui_content.h"

content::content(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::content)
{
    ui->setupUi(this);
}
const QString content::savepath = "userdiary.txt";
content::~content()
{
    delete ui;
}

void content::on_pushButton_clicked()
{
    QFile file(savepath);
    file.open(QIODevice::Append);
    if(file.isOpen())
    {
        QTextStream out(&file);
        QDateTime currentDateTime = QDateTime::currentDateTime();
        out << currentDateTime.toString("yyyy-MM-dd hh:mm:ss\n");
        QString diary = ui->textEdit->toPlainText();
        out<<diary<<"\n";
        file.close();
    }
    emit close_con_signals();
}


void content::on_pushButton_2_clicked()
{
    emit close_con_signals();
}

