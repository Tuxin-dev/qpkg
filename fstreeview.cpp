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
** \file        fstreeview.cpp
** \brief       Definition file of the class 'FsTreeView'.
**
**              This class provides a view of the file system.
**
** \author      Jean-Pierre Blasi
** \version     1.0.0
** \since       Created on 01/25/2020
** \date        January, 25th 2020
**
******************************************************************************/
#include "fstreeview.h"
#include <QModelIndexList>
#include <QDesktopWidget>
#include <QApplication>
#include <QFileSystemModel>


#include "filesystemmodel.h"

FsTreeView::FsTreeView()
{
    this->fs_model.setRootPath("");
    this->setModel(&fs_model);

    this->setAnimated(false);
    this->setIndentation(20);
    this->setSortingEnabled(true);

    QDesktopWidget * desktop = QApplication::desktop();
    const QSize availableSize = desktop->availableGeometry(this).size();
    this->resize(availableSize / 2);
    this->setColumnWidth(0, this->width() / 3);

    this->setWindowTitle(QObject::tr("Dir View"));
    //tree.show();
}

//void TreeView::changeFileList(QModelIndex& index, QModelIndex& index2) {

//}

void FsTreeView::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected) {
    Q_UNUSED(deselected)
      const auto *m = qobject_cast<FileSystemModel *>(this->model());
    if(m){
        for(const QModelIndex &index: selected.indexes()){
            //m->itemFromIndex(index)->setCheckState(Qt::Checked);
        }
    }
}

