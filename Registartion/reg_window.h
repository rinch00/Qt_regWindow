#ifndef REG_WINDOW_H
#define REG_WINDOW_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStandardPaths>
#include <QDir>
#include <QDebug>

namespace Ui {
class reg_window;
}

class reg_window : public QDialog
{
    Q_OBJECT

public:
    explicit reg_window(QWidget *parent = nullptr);
    ~reg_window();

signals:
    void backclick_button_clicked();

private slots:
    void on_Name_lineEdit_textEdited(const QString &arg1);
    void on_Paswword_lineEdit_textEdited(const QString &arg1);
    void on_Confirm_lineEdit_textEdited(const QString &arg1);
    void on_Register_pushButton_clicked();

    void on_Email_lineEdit_textEdited(const QString &arg1);

    void on_Back_pushButton_clicked();

private:
    Ui::reg_window *ui;

    QString username;
    QString email;
    QString password;
    QString confirmPassword;

    void saveUserData();
};

#endif // REG_WINDOW_H
