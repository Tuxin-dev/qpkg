#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QObject>
#include <QTabWidget>
#include <QList>

struct TAB_DATA {
    bool dirty;
    QString name;
};

typedef struct TAB_DATA data_t;

class TabWidget : public QTabWidget
{
public:
    TabWidget(QWidget *parent = nullptr);

private:
    QList<data_t> tab_data;

};

#endif // TABWIDGET_H
