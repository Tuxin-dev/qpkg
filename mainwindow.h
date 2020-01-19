#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QDir>

#include "package.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Package *package;
    QSettings *settings;
    QString workspace;
    QString root_dir;
    void openSettings(void);
    void createNewTab(void);
    void createPackage(QString &filename);

public slots:
    void onTabBarClicked(int index);
    void onTabClosed(int index);
private slots:
    void on_action_Workspace_triggered();
    void on_action_Root_directory_triggered();
    void on_action_Open_triggered();
};

#endif // MAINWINDOW_H
