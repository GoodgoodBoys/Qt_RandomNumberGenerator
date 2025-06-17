#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class Setting;
}

class ParameterList
{
public:
    int limitL;
    int limitH;
};

class Setting : public QDialog
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = 0);
    ~Setting();

    void initialization(int currentLimitL, int currentLimitH);

    ParameterList getReturnValue();

    ParameterList parameterList;

private:
    Ui::Setting *ui;
};

#endif // SETTING_H
