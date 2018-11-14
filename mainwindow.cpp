#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "sysinfo.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SysInfo::instance().init();
}

MainWindow::~MainWindow()
{
    delete ui;
}
