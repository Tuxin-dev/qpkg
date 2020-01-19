#ifndef FILESYSTEMMODEL_H
#define FILESYSTEMMODEL_H
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
** \file        filesystemmodel.h
** \brief       Declaration file of the class 'FileSystemModel'.
**
**              This class provides a template for a view of the file system.
**
** \author      Jean-Pierre Blasi
** \version     1.0.0
** \since       Created on 01/24/2020
** \date        January, 24th 2020
**
******************************************************************************/
#include <QFileSystemModel>
#include <QModelIndex>
#include <QPersistentModelIndex>
#include <QSet>

class FileSystemModel : public QFileSystemModel
{
        Q_OBJECT

public:
    FileSystemModel();
    /**----------------------------------------------------------------------------
    ** \fn        void selectPath(QString &path)
    **
    ** \brief     Path selection function.
    **
    **            The checkbox is activated
    **
    ** \param     path Reference to the string containing the path.
    **
    ** \return    None
    **
    ** \author    Jean-Pierre Blasi
    ** \version   1.0.0
    ** \since     Created on 01/24/2020
    ** \date      January, 24th 2020
    **
    **---------------------------------------------------------------------------*/
    void selectPath(QString &path);
    /**----------------------------------------------------------------------------
    ** \fn        void deselectPath(QString &path)
    **
    ** \brief     Path deselection function.
    **
    **            The checkbox is deactivated
    **
    ** \param     path Reference to the string containing the path.
    **
    ** \return    None
    **
    ** \author    Jean-Pierre Blasi
    ** \version   1.0.0
    ** \since     Created on 01/24/2020
    ** \date      January, 24th 2020
    **
    **---------------------------------------------------------------------------*/
    void deselectPath(QString &path);

private:
    QSet<QPersistentModelIndex> checklist;  // List of checked paths

    // Reimplemented functions of QFileSystemModel class
    Qt::ItemFlags flags(const QModelIndex& index) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role);
    QVariant data(const QModelIndex& index,int role) const;
};

#endif // FILESYSTEMMODEL_H
