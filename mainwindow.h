#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    //Got this from lecture
    void actionNew();
    void actionOpen();
    void actionSave();
    void actionSaveAs();
    void actionClose();

private:
    Ui::MainWindow *ui;

    QString _filename{""};
    void createActions();
    void setupMenuBar();
    void setupToolBar();
    void setupMenu();
    void init();

};
#endif // MAINWINDOW_H
