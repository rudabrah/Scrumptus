#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    init();
    //trying other ways to connect, but it gives an error for I-value and the use of & - Google said it had something to do
    //with the MainWindow::actionOpen returning an unnamed temporary object...
    //connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::actionOpen());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actionNew()
{
    _filename = "";
    ui->textEdit->clear();//Assuming that in cicking "New" - you want to start fresh
    ui->statusbar->showMessage("Making new file!");
    qInfo("New");
}

void MainWindow::actionOpen()
{
    QString path = QFileDialog::getOpenFileName(this, "Open a file");
    QFile file(path);

    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }
    QTextStream stream(&file);
    ui->textEdit->setPlainText(stream.readAll());
    file.close();

    ui->statusbar->showMessage(path);
    _filename = path;


}

void MainWindow::actionSave()
{
    QString path = _filename;

    if(_filename.isEmpty())
    {
        path = QFileDialog::getSaveFileName(this, "Save file");//Dette er en funksjon for å lage et filnavn.
    }


    QFile file(path);

    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this, "Error", file.errorString());
    }

    QTextStream stream(&file);
    stream << ui->textEdit->toPlainText();
    file.close();

    ui->statusbar->showMessage(path);
    _filename = path;
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
    //setupToolBar();
    //setupMenu();
}


//I feel like this is a weird way to get the functions to work with their buttons..
void MainWindow::on_actionOpen_triggered()
{
    actionOpen();
}


void MainWindow::on_actionNew_triggered()
{
    actionNew();
}


void MainWindow::on_actionSave_triggered()
{
    actionSave();
}

