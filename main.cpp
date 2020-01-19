#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QCoreApplication>
#include "fstreeview.h"
#include <QDesktopWidget>
#include <QGridLayout>
#include <QFrame>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    //FsTreeView tree;

    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    //QFrame
    //QDockWidgetArea;
    //tree.setParent(&w);

    //QWidget widget;
    //tree.setParent(&widget);

    //QGridLayout* layout = new QGridLayout;
    //layout->addWidget(&widget);
    //layout->setAlignment(&widget, Qt::AlignCenter);
    //widget.setLayout(layout);
    //w.setCentralWidget(&widget);
    //w.addDockWidget(Qt::RightDockWidgetArea, QDockWidget)

    w.show();

    return app.exec();
}
