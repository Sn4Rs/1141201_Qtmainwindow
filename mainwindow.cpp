#include "mainwindow.h"
#include <QDateTime>
#include <cstdlib>
#include <ctime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Set window properties
    setWindowTitle("Design Window - Dark Theme");
    resize(800, 600);

    // Create central widget
    centralLabel = new QLabel("Welcome to the Dark Theme Application!", this);
    centralLabel->setAlignment(Qt::AlignCenter);
    setCentralWidget(centralLabel);

    // Create menu bar with 3 menus
    createMenuBar();

    // Create status bar
    statusBar()->showMessage("Ready");

    // Seed random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

MainWindow::~MainWindow() {}

void MainWindow::createMenuBar()
{
    // Menu 1: File Menu
    QMenu *fileMenu = menuBar()->addMenu("&File");

    QAction *openAction = new QAction("&Open", this);
    openAction->setShortcut(QKeySequence::Open);
    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
    fileMenu->addAction(openAction);

    QAction *saveAction = new QAction("&Save", this);
    saveAction->setShortcut(QKeySequence::Save);
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveFile);
    fileMenu->addAction(saveAction);

    fileMenu->addSeparator();

    QAction *exitAction = new QAction("E&xit", this);
    exitAction->setShortcut(QKeySequence::Quit);
    connect(exitAction, &QAction::triggered, this, &MainWindow::exitApp);
    fileMenu->addAction(exitAction);

    // Menu 2: Edit Menu
    QMenu *editMenu = menuBar()->addMenu("&Edit");

    QAction *preferencesAction = new QAction("&Preferences", this);
    preferencesAction->setShortcut(QKeySequence::Preferences);
    connect(preferencesAction, &QAction::triggered, this, &MainWindow::showPreferences);
    editMenu->addAction(preferencesAction);

    // Menu 3: Tools Menu (Random functionality)
    QMenu *toolsMenu = menuBar()->addMenu("&Tools");

    QAction *randomNumberAction = new QAction("&Generate Random Number", this);
    randomNumberAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_R));
    connect(randomNumberAction, &QAction::triggered, this, &MainWindow::generateRandomNumber);
    toolsMenu->addAction(randomNumberAction);

    QAction *dateTimeAction = new QAction("&Show Date/Time", this);
    dateTimeAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_D));
    connect(dateTimeAction, &QAction::triggered, this, &MainWindow::showDateTime);
    toolsMenu->addAction(dateTimeAction);

    QAction *calculatorAction = new QAction("&Quick Calculator", this);
    calculatorAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_K));
    connect(calculatorAction, &QAction::triggered, this, &MainWindow::calculateSum);
    toolsMenu->addAction(calculatorAction);

    // Help Menu (Bonus)
    QMenu *helpMenu = menuBar()->addMenu("&Help");

    QAction *aboutAction = new QAction("&About", this);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAbout);
    helpMenu->addAction(aboutAction);
}

void MainWindow::showAbout()
{
    QMessageBox::about(this, "About",
                       "Design Window Application\n"
                       "Version 1.0\n\n"
                       "A Qt application with dark theme\n"
                       "and menu bar functionality.");
}

void MainWindow::exitApp()
{
    close();
}

void MainWindow::openFile()
{
    statusBar()->showMessage("Open file action triggered", 3000);
    QMessageBox::information(this, "Open", "Open file functionality placeholder");
}

void MainWindow::saveFile()
{
    statusBar()->showMessage("Save file action triggered", 3000);
    QMessageBox::information(this, "Save", "Save file functionality placeholder");
}

void MainWindow::showPreferences()
{
    statusBar()->showMessage("Preferences opened", 3000);
    QMessageBox::information(this, "Preferences", "Preferences dialog placeholder");
}

void MainWindow::generateRandomNumber()
{
    int randomNum = std::rand() % 1000 + 1;
    QString message = QString("Random Number: %1").arg(randomNum);
    centralLabel->setText(message);
    statusBar()->showMessage(message, 3000);
    QMessageBox::information(this, "Random Number Generator",
                             QString("Your random number is: %1").arg(randomNum));
}

void MainWindow::showDateTime()
{
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    centralLabel->setText(QString("Current Date/Time: %1").arg(currentDateTime));
    statusBar()->showMessage(currentDateTime, 3000);
    QMessageBox::information(this, "Current Date/Time", currentDateTime);
}

void MainWindow::calculateSum()
{
    bool ok1, ok2;
    double num1 = QInputDialog::getDouble(this, "Quick Calculator",
                                           "Enter first number:", 0, -10000, 10000, 2, &ok1);
    if (!ok1) return;

    double num2 = QInputDialog::getDouble(this, "Quick Calculator",
                                           "Enter second number:", 0, -10000, 10000, 2, &ok2);
    if (!ok2) return;

    double sum = num1 + num2;
    QString result = QString("%1 + %2 = %3").arg(num1).arg(num2).arg(sum);
    centralLabel->setText(result);
    statusBar()->showMessage(result, 3000);
    QMessageBox::information(this, "Calculator Result", result);
}
