#include "dialog.h"
#include <QBuffer>
#include <QtCore/QDebug>
#include<QSharedMemory>


Dialog::Dialog(QWidget *parent)
  : QDialog(parent), sharedMemory("QSharedMemoryExample")
{
    ui.setupUi(this);

    connect(ui.loadFromSharedMemoryButton,
            SIGNAL(clicked()),
            SLOT(loadFromMemory()));
}

QString Dialog::loadFromMemory()
{
    sharedMemory.setKey("server1234");
sharedMemory.registerUserData();

    QBuffer buffer;
    QDataStream in(&buffer);
    //QByteArray in;

    QString text;
    sharedMemory.lock();
    buffer.setData((char*)sharedMemory.constData(), sharedMemory.size());
    buffer.open(QBuffer::ReadOnly);
    in >> text;
    sharedMemory.unlock();
    if (text=="stop")
    {
    ui.label->setText(tr("da nhan duoc"));
    }
    else
    {
        ui.label->setText(tr("Chua nhan dc"));
    }
    return text;

}

