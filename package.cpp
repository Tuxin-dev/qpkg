#include "package.h"

Package::Package(QObject *parent, package_t type) : QObject(parent)
{
    this->type = type;
}


