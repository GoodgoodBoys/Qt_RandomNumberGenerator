#include "setting.h"
#include "ui_setting.h"

#include <QDebug>

Setting::Setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);

    this->setWindowTitle("Setting");

    connect(ui->buttonSettingCancel, &QPushButton::clicked, this, &Setting::close);
    connect(ui->buttonSettingConfirm, &QPushButton::clicked, this, [=]() {
        accept();
        close();
    });
}

Setting::~Setting()
{
    delete ui;
}

void Setting::initialization(int currentLimitL, int currentLimitH)
{
    parameterList.limitL = currentLimitL;
    parameterList.limitH = currentLimitH;

    ui->spinBoxL->setValue(parameterList.limitL);
    ui->spinBoxH->setValue(parameterList.limitH);
}

ParameterList Setting::getReturnValue()
{
    parameterList.limitL = ui->spinBoxL->value();
    parameterList.limitH = ui->spinBoxH->value();
    return parameterList;
}



