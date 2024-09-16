#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "auth_window.h"
#include "reg_window.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showAuthWindow();  // Метод для показа окна авторизации
    void showRegWindow();   // Метод для показа окна регистрации
    //void display();

private:
    Ui::MainWindow *ui;
    auth_window ui_Auth;
    auth_window *authWindow; // Окно авторизации
    reg_window *regWindow;   // Окно регистрации

private slots:
    void onRegistrationCompleted();  // Слот, который вызывается после успешной регистрации
};

#endif // MAINWINDOW_H
