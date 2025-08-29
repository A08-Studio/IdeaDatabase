/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEditTopLevelCategory;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEditMidLevelCategory;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonApply;
    QPushButton *pushButtonClose;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName("SettingsDialog");
        SettingsDialog->resize(454, 417);
        verticalLayout_3 = new QVBoxLayout(SettingsDialog);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        groupBox = new QGroupBox(SettingsDialog);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        textEditTopLevelCategory = new QTextEdit(groupBox);
        textEditTopLevelCategory->setObjectName("textEditTopLevelCategory");

        verticalLayout->addWidget(textEditTopLevelCategory);


        horizontalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(SettingsDialog);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        textEditMidLevelCategory = new QTextEdit(groupBox_2);
        textEditMidLevelCategory->setObjectName("textEditMidLevelCategory");

        verticalLayout_2->addWidget(textEditMidLevelCategory);


        horizontalLayout_2->addWidget(groupBox_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonApply = new QPushButton(SettingsDialog);
        pushButtonApply->setObjectName("pushButtonApply");

        horizontalLayout->addWidget(pushButtonApply);

        pushButtonClose = new QPushButton(SettingsDialog);
        pushButtonClose->setObjectName("pushButtonClose");

        horizontalLayout->addWidget(pushButtonClose);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(SettingsDialog);
        QObject::connect(pushButtonClose, &QPushButton::clicked, SettingsDialog, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QCoreApplication::translate("SettingsDialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SettingsDialog", "Top-Level Category", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SettingsDialog", "Mid-Level Category", nullptr));
        pushButtonApply->setText(QCoreApplication::translate("SettingsDialog", "Apply", nullptr));
        pushButtonClose->setText(QCoreApplication::translate("SettingsDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
