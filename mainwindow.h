#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_radioButton_pressed();

    void on_radioButton_2_pressed();

    void on_radioButton_3_pressed();

    void on_radioButton_4_pressed();

    void on_radioButton_5_pressed();

    void on_radioButton_7_pressed();

    void on_radioButton_8_pressed();

    void on_radioButton_6_pressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
