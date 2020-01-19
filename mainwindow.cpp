#include <QTextEdit>
#include <QStandardPaths>
#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    package = nullptr;

    openSettings();
    connect(ui->tabWidget, SIGNAL(tabBarClicked(int)),
            this, SLOT(onTabBarClicked(int)));
    connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)),
            this, SLOT(onTabClosed(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openSettings(void)
{
    QString app_dir = QCoreApplication::applicationDirPath();
    QString default_workspace = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation)
                              + QString("/qpkg/");
    QString default_rootdir = app_dir;
    QString filename(app_dir + "/qpkg.conf");

    settings = new QSettings(filename, QSettings::IniFormat);
    workspace = settings->value("workspace", default_workspace).toString();
    root_dir = settings->value("rootdir", default_rootdir).toString();
    ui->listFiles->addItem(workspace);
}

// Slots
// -----
void MainWindow::onTabBarClicked(int index)
{
    if (index == 0) {   // Create new tab
        QTextEdit *new_script = new QTextEdit();
        index = ui->tabWidget->addTab(new_script, "New");
        ui->tabWidget->setTabsClosable(true);
    }
}

void MainWindow::createNewTab(void)
{

}

void MainWindow::onTabClosed(int index)
{
    if (index != 0) {
        ui->tabWidget->removeTab(index);
    }
    else {
        createNewTab();
    }
}

void MainWindow::on_action_Workspace_triggered()
{
    workspace = QFileDialog::getExistingDirectory(this,
                                    tr("Select Workspace Directory"),
                                    workspace,
                                    QFileDialog::ShowDirsOnly
                                        | QFileDialog::DontResolveSymlinks);
    settings->setValue("workspace", workspace);
    ui->listFiles->addItem(workspace);
}

void MainWindow::on_action_Root_directory_triggered()
{
    root_dir = QFileDialog::getExistingDirectory(this,
                                    tr("Select Workspace Directory"),
                                    root_dir,
                                    QFileDialog::ShowDirsOnly
                                        | QFileDialog::DontResolveSymlinks);
    settings->setValue("rootdir", root_dir);
    ui->listFiles->addItem(root_dir);
}

void MainWindow::createPackage(QString &filename)
{
    package = new Package(this, IPK_TYPE);
    //package->setFilename(filename);
}

void MainWindow::on_action_Open_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                 tr("Select Package File"),
                                 workspace,
                                 tr("Packages (*.ipk)"),
                                 Q_NULLPTR);
    if (!filename.isNull()) {
        createPackage(filename);
    }
}
