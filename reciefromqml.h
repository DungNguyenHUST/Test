#ifndef RECIEFROMQML_H
#define RECIEFROMQML_H

#include <QObject>
#include <qsharedmemory.h>
#include <qdialog.h>
#include <qsharedmemory.h>
#include "ui_dialog.h"

class Dialog:public QDialog
{
    Q_OBJECT

public :
    Dialog(QWidget *parent = 0);

    void loadFromMemory();
    void updateEvent();


private:
   QSharedMemory sharedMemory;
};

#endif // RECIEFROMQML_H
