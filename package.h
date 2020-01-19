#ifndef PACKAGE_H
#define PACKAGE_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QFile>

enum PACKAGE_TYPE_LIST {
    NONE_TYPE = 0,
    IPK_TYPE  = 1,
    OPK_TYPE  = 2,
    DEB_TYPE  = 3,
    RPM_TYPE  = 4
};

typedef enum PACKAGE_TYPE_LIST package_t;

class Package : public QObject
{
    Q_OBJECT
public:
    explicit Package(QObject *parent = nullptr, package_t type = IPK_TYPE);

signals:

public slots:

private:
    package_t type;
    QString name;
    QString root_path;
    QString scripts_list;
    QStringList paths_list;
};

#endif // PACKAGE_H
