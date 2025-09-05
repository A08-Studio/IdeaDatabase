#ifndef CALENDARDIALOG_H
#define CALENDARDIALOG_H

#include <QDialog>

namespace Ui {
class CalendarDialog;
}

class CalendarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CalendarDialog(QWidget *parent = nullptr);
    ~CalendarDialog();
    void setDate(QDate d);
    QDate date();

private:
    Ui::CalendarDialog *ui;
};

#endif // CALENDARDIALOG_H
