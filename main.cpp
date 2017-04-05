#include "mainwindow.h"
#include "reciefromqml.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog dialog;
      dialog.show();

    return a.exec();
}
