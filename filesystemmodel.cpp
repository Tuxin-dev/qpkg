/* ****************************************************************************
**                                                                           **
**                           Tuxin - GPLv2 license                           **
**                                                                           **
**                       Version 1.0.0   24/01/2020                          **
**                                                                           **
** ***************************************************************************/
/** \addtogroup FileSystemModel
 * \{
 */
/******************************************************************************
** \file        filesystemmodel.cpp
** \brief       Definition file of the class 'FileSystemModel'.
**
**              This class provides a template for a view of the file system.
**
** \author      Jean-Pierre Blasi
** \version     1.0.0
** \since       Created on 01/24/2020
** \date        January, 24th 2020
**
******************************************************************************/
#include "filesystemmodel.h"

FileSystemModel::FileSystemModel()
{

}

/*---------------------------------------------------------------------------*/
void FileSystemModel::selectPath(QString &path)
/*---------------------------------------------------------------------------*/
{
    QModelIndex index = this->index(path);

    setData(index, Qt::Checked, Qt::CheckStateRole);
}

/*---------------------------------------------------------------------------*/
void FileSystemModel::deselectPath(QString &path)
/*---------------------------------------------------------------------------*/
{
    QModelIndex index = this->index(path);

    setData(index, Qt::Unchecked, Qt::CheckStateRole);
}

/**----------------------------------------------------------------------------
** \fn        QVariant FileSystemModel
**                             ::data(const QModelIndex& index, int role) const
**
** \brief     Read data from the file system model.
**
** \param     index Index of the item.
** \param     role Role of data, in the item.
**
** \return    The data stored under the given role for the item
**            referred to by the index.
**
** \author    Jean-Pierre Blasi
** \version   1.0.0
** \since     Created on 01/24/2020
** \date      January, 24th 2020
**
**---------------------------------------------------------------------------*/
QVariant FileSystemModel::data(const QModelIndex& index, int role) const
{
    if (index.column() == 0) {
        switch(role) {
            case Qt::CheckStateRole:
                return checklist.contains(index) ? Qt::Checked : Qt::Unchecked;
            default:
                break;
        }
    }

    return QFileSystemModel::data(index, role);
}

/**----------------------------------------------------------------------------
** \fn        Qt::ItemFlags FileSystemModel
**                                 ::flags(const QModelIndex& index) const
**
** \brief     Get the flags of an item.
**
**            The base class implementation returns a combination of flags
**            that enables the item (ItemIsEnabled) and allows it to be
**            selected (ItemIsSelectable). This function adds the flag
**            'ItemIsUserCheckable' for column 0.
**
** \param     index Index of the item.
**
** \return    A value with flags of the item.
**
** \author    Jean-Pierre Blasi
** \version   1.0.0
** \since     Created on 01/24/2020
** \date      January, 24th 2020
**
**---------------------------------------------------------------------------*/
Qt::ItemFlags FileSystemModel::flags(const QModelIndex& index) const
{
    Qt::ItemFlags myFlags = QFileSystemModel::flags(index);
    if (index.column() == 0) {
        myFlags |= Qt::ItemIsUserCheckable;
    }

    return myFlags;
}

/**----------------------------------------------------------------------------
** \fn        bool FileSystemModel::setData(const QModelIndex& index,
**                                          const QVariant& value, int role)
**
** \brief     Sets the role data for the item at index to value.
**
**            This function inserts/removes the index of item to the list of
**            checked path, when 'role' is 'CheckStateRole'.
**            The dataChanged() signal is emitted when the data was
**            successfully set.
**
** \param     index Index of the item.
** \param     value Value to write.
** \param     role Role of data, in the item.
**
** \return    true if successful; otherwise returns false.
**
** \author    Jean-Pierre Blasi
** \version   1.0.0
** \since     Created on 01/24/2020
** \date      January, 24th 2020
**
**---------------------------------------------------------------------------*/
bool FileSystemModel::setData(const QModelIndex& index, const QVariant& value,
                              int role)
{
    if (role == Qt::CheckStateRole) {
        if (value == Qt::Checked) {
            checklist.insert(index);
        } else {
            checklist.remove(index);
        }
        // fileInfo, fileName, ou filePath
        // isDir, rootDirectory, rootPath, index

        emit dataChanged(index, index);
        return true;
    }
    return QFileSystemModel::setData(index, value, role);
}

