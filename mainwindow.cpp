#include <random>

#include <QTimer>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setting.h"

#define DefaultLimitL 0
#define DefaultLimitH 100

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    historyViewListModel = new QStandardItemModel(this);
    std::random_device seed;
    QTimer * timer = new QTimer(this);

    this->setWindowTitle("Random Data Creater");
    ui->randomNumDisplayer->setStyleSheet("font-size: 50px; font-weight: bold; color: blue;");

    timer->start(30);

    this->limitL = DefaultLimitL;
    this->limitH = DefaultLimitH;

    gen = std::mt19937(seed());
    dist = std::uniform_int_distribution<>(this->limitL, this->limitH);

    ui->historyListView->setModel(historyViewListModel);

    connect(timer, &QTimer::timeout, [=]() {
        ui->randomNumDisplayer->setNum(dist(gen));
    });

    connect(ui->buttonGetData, &QPushButton::clicked, [=]() {
        QStandardItem * currentItem = new QStandardItem(ui->randomNumDisplayer->text());
        historyViewListModel->insertRow(0, currentItem);
    });

    connect(ui->buttonClear, &QPushButton::clicked, [=]() {
        historyViewListModel->clear();
    });

    connect(ui->actionLimitSet, &QAction::triggered, this, &MainWindow::SettingWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SettingWindow() {
    Setting settingDialog(this);
    settingDialog.initialization(this->limitL, this->limitH);

    if(settingDialog.exec() == QDialog::Accepted) {
        ParameterList parameterList = settingDialog.getReturnValue();
        limitL = parameterList.limitL;
        limitH = parameterList.limitH;
        dist = std::uniform_int_distribution<>(this->limitL, this->limitH);
    }
}
