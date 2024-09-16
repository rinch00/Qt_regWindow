#ifndef AUTH_WINDOW_H
#define AUTH_WINDOW_H

#include <QDialog>
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <QApplication>

namespace Ui {
class auth_window;
}

class auth_window : public QDialog
{
    Q_OBJECT

public:
    explicit auth_window(QWidget *parent = nullptr);
    ~auth_window();

signals:
    void register_button_clicked();

private slots:
    void on_UserLineEdit_textEdited(const QString &arg1);
    void on_PasswordLineEdit_textEdited(const QString &arg1);
    void on_LoginPushButton_clicked();
    void on_RegisterPushButton_clicked();
    void on_exitPushButton_clicked();

private:
    Ui::auth_window *ui;

    QString username;
    QString email;
    QString password;
};

#endif // AUTH_WINDOW_H
