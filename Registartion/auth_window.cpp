#include "auth_window.h"
#include "ui_auth_window.h"


auth_window::auth_window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::auth_window)
{
    ui->setupUi(this);
    // красный цвет для кнопки выхода
    ui->exitPushButton->setStyleSheet("background-color: red; color: white;");
    // связыват нажатие кнопкой с определнный функцией выполнения
    connect(ui->exitPushButton, &QPushButton::clicked, this, &auth_window::on_exitPushButton_clicked);
}

auth_window::~auth_window()
{
    delete ui;
}


void auth_window::on_UserLineEdit_textEdited(const QString &arg1)
{
    username = arg1;
    email = arg1;
}


void auth_window::on_PasswordLineEdit_textEdited(const QString &arg1)
{
    password = arg1;
}


void auth_window::on_LoginPushButton_clicked()
{
    QString enteredUsernameOrEmail = ui->UserLineEdit->text();  // Получаем введённый логин или email
    QString enteredPassword = ui->PasswordLineEdit->text();     // Получаем введённый пароль

    //QFile file("/Users/rincho/Desktop/userdata.txt");  // Путь к файлу с данными

    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);  // Получаем путь к рабочему столу текущего пользователя
    QString filePath = QDir(desktopPath).filePath("userdata.txt");
    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        bool loginSuccess = false;

        while (!in.atEnd()) {
            QString username = in.readLine().split(": ").last();  // Читаем логин
            QString email = in.readLine().split(": ").last();     // Читаем email
            QString password = in.readLine().split(": ").last();  // Читаем пароль
            in.readLine();  // Пропускаем строку с разделителем "--------------------------"

            // проверяем полученные данные username | email | password
            if ((enteredUsernameOrEmail == username || enteredUsernameOrEmail == email) && enteredPassword == password) {
                if (enteredUsernameOrEmail == email) {
                    qDebug() << "Вход выполнен успешно!";
                    qDebug() << "Login: " << email;
                    qDebug() << "Password: " << password;
                    QMessageBox::information(this, "Login", "Вход выполнен успешно");
                    loginSuccess = true;
                    break;
                } else {
                    qDebug() << "Вход выполнен успешно!";
                    qDebug() << "Login: " << username;
                    qDebug() << "Password: " << password;
                    QMessageBox::information(this, "Login", "Вход выполнен успешно");
                    loginSuccess = true;
                    break;
                }
            }
        }

        if (!loginSuccess) {
            qDebug() << "Неверный логин/почта или пароль!";
            QMessageBox::warning(this, "Login", "Неправильный логин пользователя или пароль");

        }

        file.close();
    } else {
        qDebug() << "Ошибка при открытии файла!";
        QMessageBox::warning(this, "Login", "Ошибка при открытии файла");
    }

}


void auth_window::on_RegisterPushButton_clicked()
{
    emit register_button_clicked();
}


void auth_window::on_exitPushButton_clicked()
{
    QApplication::quit();
}

