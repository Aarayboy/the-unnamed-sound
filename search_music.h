#ifndef SEARCH_MUSIC_H
#define SEARCH_MUSIC_H

#include <QWidget>
#include<Qdialog>
namespace Ui {
class search_music;
}

class search_music : public QDialog
{
    Q_OBJECT

public:
    explicit search_music(QWidget *parent = nullptr);
    ~search_music();

private:
    Ui::search_music *ui;
};

#endif // SEARCH_MUSIC_H
