#include "reciefromqml.h"
#include <QFileDialog>
#include <QBuffer>
#include <QtCore/QDebug>



void RecieFromQML::loadFromMemory()
{
    if (!sharedMemory.attach())
    {
        qDebug()<<"No event.Unable to attach to shared memory segment, first initial memory";
        return;
    }

    QBuffer buffer;
    QDataStream in(&buffer);

    QString event;
    sharedMemory.lock();
    buffer.setData((char*)sharedMemory.constData(), sharedMemory.size());
    buffer.open(QBuffer::ReadOnly);
    in >> event;
    sharedMemory.unlock();

     qDebug() << "SHARED TEXT IS: " << event;

     if (event=="stop")
     {
             updateEvent();
     }
     else
     {
         qDebug()<<"no event to shared";
     }
}
void RecieFromQML::updateEvent()
{
    qDebug() << "stoped";
}

