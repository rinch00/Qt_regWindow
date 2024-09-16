#include "reg_window.h"
#include "ui_reg_window.h"

reg_window::reg_window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::reg_window)
{
    ui->setupUi(this);
}

reg_window::~reg_window()
{
    delete ui;
}


void reg_window::on_Name_lineEdit_textEdited(const QString &arg1)
{
    username = arg1;
}


void reg_window::on_Email_lineEdit_textEdited(const QString &arg1)
{
    email = arg1;
}


void reg_window::on_Paswword_lineEdit_textEdited(const QString &arg1)
{
    password = arg1;
}


void reg_window::on_Confirm_lineEdit_textEdited(const QString &arg1)
{
    confirmPassword = arg1;
}


void reg_window::on_Register_pushButton_clicked()
{
    // проверяет что строки не пустые и пользователь ввел значения
    if (username.isEmpty() || password.isEmpty() || confirmPassword.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Registration", "Пожалуйста, заполните все поля.");
        return;
    }

    // проверка на поддтверждение пароля
    if (password != confirmPassword) {
        QMessageBox::warning(this, "Registration", "Пароли не совпадают.");
        return;
    }

    qDebug() << "Registering username: " << username;
    qDebug() << "Registering Email: " << email;
    qDebug() << "Registering password: " << password;

    // Сохраняем данные пользователя в файл
    saveUserData();

    QMessageBox::information(this, "Registration", "Регистрация завершена успешно!");

    accept();
}

void reg_window::saveUserData()
{
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation); // указывается путь к работчему столу
    QString filePath = QDir(desktopPath).filePath("userdata.txt"); // указывается на фаил созданныый на рабочем столе

    QFile file(filePath);
    if (!file.open(QIODevice::Append | QIODevice::Text)) { // открытие файла в режиме добавления и то что строки будут обрабатываться как текст а не бинарные данные
        QMessageBox::warning(this, "Error", "Не удалось открыть файл для записи.");
        return;
    }

    QTextStream out(&file);
    out << "Username: " << username << "\n";
    out << "Email: " << email << "\n";
    out << "Password: " << password << "\n";
    out << "--------------------------" "\n";
    file.close();
}





void reg_window::on_Back_pushButton_clicked()
{
    emit backclick_button_clicked();
}

