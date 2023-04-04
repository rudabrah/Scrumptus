#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actionNew()
{

}

void MainWindow::actionOpen()
{

}

void MainWindow::actionSave()
{

}

void MainWindow::actionSaveAs()
{

}

void MainWindow::actionClose()
{

}

void MainWindow::createActions()
{

}

void MainWindow::setupMenuBar()
{

}

void MainWindow::setupToolBar()
{
    //make a toolbar with funtional buttons
    QToolBar* toolbar = addToolBar("The toolbar");

    //These are linked to the private slots in the header file
    toolbar->addAction("New", this, SLOT(actionNew()));
    toolbar->addAction("Save", this, SLOT(actionSave()));
    toolbar->addAction("Open", this, SLOT(actionOpen()));
    toolbar->addAction("Save as", this, SLOT(actionSaveAs()));
    toolbar->addAction("Close", this, SLOT(actionClose()));



}

void MainWindow::setupMenu()
{

}

void MainWindow::init()
{

}
