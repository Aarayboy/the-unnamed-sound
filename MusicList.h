#ifndef MUSICLIST_H
#define MUSICLIST_H

#include <QObject>
#include <QString>
#include <QList>
#include <QTableWidget>

class playlist : public QObject
{
    Q_OBJECT
public:
    explicit playlist(QObject *parent = nullptr);
signals:
    void play_list_clean();
    void add_File_signal();

public slots:


protected:
    void contextMenuEvent(QContextMenuEvent *);
    void closeEvent(QCloseEvent *);

private slots:
    void clear_play_list();
    void add_File_slot();

};

#endif // MUSICLIST_H
