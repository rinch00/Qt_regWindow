#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets/qpushbutton.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    authWindow(new auth_window(this)),  // Инициализируем окно авторизации
    regWindow(new reg_window(this))
{

    ui->setupUi(this);
// Отобразить окно авторизации при старте
showAuthWindow();

// Подключаем кнопку регистрации к показу окна регистрации
connect(authWindow, &auth_window::register_button_clicked, this, &MainWindow::showRegWindow);

// Подключаем сигнал регистрации к возвращению в окно авторизации
connect(regWindow, &reg_window::accepted, this, &MainWindow::onRegistrationCompleted);

connect(regWindow, &reg_window::backclick_button_clicked, this, &MainWindow::showAuthWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete authWindow;
    delete regWindow;
}

// void MainWindow::display()
// {
//     ui_Auth.show();
// }

void MainWindow::showAuthWindow()
{
    authWindow->show();
    regWindow->hide();  // Скрываем окно регистрации, если оно открыто
}

void MainWindow::showRegWindow()
{
    regWindow->show();
    authWindow->hide();  // Скрываем окно авторизации при переходе на регистрацию
}

void MainWindow::onRegistrationCompleted()
{
    // После завершения регистрации вернемся к окну авторизации
    showAuthWindow();
}
