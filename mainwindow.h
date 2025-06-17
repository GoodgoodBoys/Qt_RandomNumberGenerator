#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void SettingWindow();

    std::mt19937 gen;
    std::uniform_int_distribution<> dist;

    QStandardItemModel *historyViewListModel;

    int limitL;
    int limitH;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
