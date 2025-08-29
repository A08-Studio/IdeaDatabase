#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include <QFile>

SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    QFile t;
    t.setFileName("TopLevelCategory.txt");
    if (!t.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in1(&t);
    QString line1 = in1.readAll();
    ui->textEditTopLevelCategory->setPlainText(line1);

    QFile m;
    m.setFileName("MidLevelCategory.txt");
    if (!m.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in2(&m);
    QString line2 = in2.readAll();
    ui->textEditMidLevelCategory->setPlainText(line2);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_pushButtonApply_clicked()
{
    QFile t;
    t.setFileName("TopLevelCategory.txt");
    if (!t.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QString tt = ui->textEditTopLevelCategory->toPlainText();

    QTextStream out1(&t);
    out1 << tt;

    t.close();

    QFile m;
    m.setFileName("MidLevelCategory.txt");
    if (!m.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QString mt = ui->textEditMidLevelCategory->toPlainText();

    QTextStream out2(&m);
    out2 << mt;

    m.close();

    emit changeCategoryValue();
}

