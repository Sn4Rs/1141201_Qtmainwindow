#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QInputDialog>
#include <QLabel>
#include <QStatusBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showAbout();
    void exitApp();
    void openFile();
    void saveFile();
    void showPreferences();
    void generateRandomNumber();
    void showDateTime();
    void calculateSum();

private:
    void createMenuBar();
    QLabel *centralLabel;
};
#endif // MAINWINDOW_H
