#ifndef FSTREEVIEW_H
#define FSTREEVIEW_H
/* ****************************************************************************
**                                                                           **
**                           Tuxin - GPLv2 license                           **
**                                                                           **
**                       Version 1.0.0   25/01/2020                          **
**                                                                           **
** ***************************************************************************/
/** \addtogroup FileSystemModel
 * \{
 */
/******************************************************************************
** \file        fstreeview.h
** \brief       Declaration file of the class 'FsTreeView'.
**
**              This class provides a view of the file system.
**
** \author      Jean-Pierre Blasi
** \version     1.0.0
** \since       Created on 01/25/2020
** \date        January, 25th 2020
**
******************************************************************************/
#include <QTreeView>
#include <QStandardItemModel>
#include <QItemSelection>
#include "package.h"
#include "filesystemmodel.h"


class FsTreeView : public QTreeView
{
    Q_OBJECT

public:
    /**----------------------------------------------------------------------------
    ** \fn        FsTreeView()
    **
    ** \brief     Constructor of class.
    **
    **            This constructor
    **
    ** \author    Jean-Pierre Blasi
    ** \version   1.0.0
    ** \since     Created on 01/24/2020
    ** \date      January, 24th 2020
    **
    **---------------------------------------------------------------------------*/
    FsTreeView();

protected slots:
    void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

private:
    Package package;
    FileSystemModel fs_model;
};

#endif // FSTREEVIEW_H
