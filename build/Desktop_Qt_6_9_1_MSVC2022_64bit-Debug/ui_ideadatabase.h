/********************************************************************************
** Form generated from reading UI file 'ideadatabase.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IDEADATABASE_H
#define UI_IDEADATABASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IdeaDatabase
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionExport_to_JSON;
    QAction *actionImport_JSON;
    QAction *actionSettings;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTreeView *recordTreeView;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchLineEdit;
    QPushButton *searchPushButton;
    QGridLayout *gridLayout;
    QLabel *label_14;
    QLabel *label_13;
    QComboBox *filterTopLevelCategoryComboBox;
    QComboBox *filterMidLevelCategoryComboBox;
    QComboBox *filterStatusComboBox;
    QLabel *label_15;
    QLabel *label_16;
    QComboBox *filterPriorityComboBox;
    QTableView *recordTableView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *deletePushButton;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *updateDateLabel;
    QLabel *label_2;
    QTextEdit *appliedSectionTextEdit;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *idLabel;
    QDateEdit *dateAppliedDateEdit;
    QComboBox *statusComboBox;
    QLabel *label_3;
    QLabel *label_10;
    QLabel *label_5;
    QLineEdit *titleLineEdit;
    QLabel *label_12;
    QLineEdit *lowerLevelLineEdit;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_6;
    QComboBox *midLevelCategoryComboBox;
    QLabel *label_11;
    QLabel *label_9;
    QTextEdit *descriptionTextEdit;
    QComboBox *priorityComboBox;
    QComboBox *topLevelCategoryComboBox;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *attachmentPushButton;
    QLabel *attachmentLabel;
    QPushButton *attachmentDeletePushButton;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *addPushButton;
    QPushButton *updatePushButton;
    QPushButton *clearPushButton;
    QSpacerItem *horizontalSpacer_4;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *IdeaDatabase)
    {
        if (IdeaDatabase->objectName().isEmpty())
            IdeaDatabase->setObjectName("IdeaDatabase");
        IdeaDatabase->resize(1093, 662);
        actionNew = new QAction(IdeaDatabase);
        actionNew->setObjectName("actionNew");
        actionOpen = new QAction(IdeaDatabase);
        actionOpen->setObjectName("actionOpen");
        actionClose = new QAction(IdeaDatabase);
        actionClose->setObjectName("actionClose");
        actionExport_to_JSON = new QAction(IdeaDatabase);
        actionExport_to_JSON->setObjectName("actionExport_to_JSON");
        actionImport_JSON = new QAction(IdeaDatabase);
        actionImport_JSON->setObjectName("actionImport_JSON");
        actionSettings = new QAction(IdeaDatabase);
        actionSettings->setObjectName("actionSettings");
        centralwidget = new QWidget(IdeaDatabase);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_4 = new QHBoxLayout(centralwidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        recordTreeView = new QTreeView(groupBox);
        recordTreeView->setObjectName("recordTreeView");

        verticalLayout->addWidget(recordTreeView);


        horizontalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        searchLineEdit = new QLineEdit(groupBox_2);
        searchLineEdit->setObjectName("searchLineEdit");

        horizontalLayout->addWidget(searchLineEdit);

        searchPushButton = new QPushButton(groupBox_2);
        searchPushButton->setObjectName("searchPushButton");

        horizontalLayout->addWidget(searchPushButton);


        verticalLayout_2->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName("label_14");

        gridLayout->addWidget(label_14, 2, 0, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName("label_13");

        gridLayout->addWidget(label_13, 0, 0, 1, 1);

        filterTopLevelCategoryComboBox = new QComboBox(groupBox_2);
        filterTopLevelCategoryComboBox->setObjectName("filterTopLevelCategoryComboBox");

        gridLayout->addWidget(filterTopLevelCategoryComboBox, 2, 1, 1, 1);

        filterMidLevelCategoryComboBox = new QComboBox(groupBox_2);
        filterMidLevelCategoryComboBox->setObjectName("filterMidLevelCategoryComboBox");

        gridLayout->addWidget(filterMidLevelCategoryComboBox, 3, 1, 1, 1);

        filterStatusComboBox = new QComboBox(groupBox_2);
        filterStatusComboBox->setObjectName("filterStatusComboBox");

        gridLayout->addWidget(filterStatusComboBox, 0, 1, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName("label_15");

        gridLayout->addWidget(label_15, 3, 0, 1, 1);

        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName("label_16");

        gridLayout->addWidget(label_16, 1, 0, 1, 1);

        filterPriorityComboBox = new QComboBox(groupBox_2);
        filterPriorityComboBox->setObjectName("filterPriorityComboBox");

        gridLayout->addWidget(filterPriorityComboBox, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        recordTableView = new QTableView(groupBox_2);
        recordTableView->setObjectName("recordTableView");
        recordTableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        recordTableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout_2->addWidget(recordTableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        deletePushButton = new QPushButton(groupBox_2);
        deletePushButton->setObjectName("deletePushButton");

        horizontalLayout_2->addWidget(deletePushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_4->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        updateDateLabel = new QLabel(groupBox_3);
        updateDateLabel->setObjectName("updateDateLabel");

        gridLayout_2->addWidget(updateDateLabel, 1, 2, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        appliedSectionTextEdit = new QTextEdit(groupBox_3);
        appliedSectionTextEdit->setObjectName("appliedSectionTextEdit");

        gridLayout_2->addWidget(appliedSectionTextEdit, 4, 2, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName("label_7");

        gridLayout_2->addWidget(label_7, 6, 0, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName("label_8");

        gridLayout_2->addWidget(label_8, 7, 0, 1, 1);

        idLabel = new QLabel(groupBox_3);
        idLabel->setObjectName("idLabel");

        gridLayout_2->addWidget(idLabel, 0, 2, 1, 1);

        dateAppliedDateEdit = new QDateEdit(groupBox_3);
        dateAppliedDateEdit->setObjectName("dateAppliedDateEdit");

        gridLayout_2->addWidget(dateAppliedDateEdit, 3, 2, 1, 1);

        statusComboBox = new QComboBox(groupBox_3);
        statusComboBox->setObjectName("statusComboBox");

        gridLayout_2->addWidget(statusComboBox, 2, 2, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName("label_10");

        gridLayout_2->addWidget(label_10, 9, 0, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        titleLineEdit = new QLineEdit(groupBox_3);
        titleLineEdit->setObjectName("titleLineEdit");

        gridLayout_2->addWidget(titleLineEdit, 9, 2, 1, 1);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName("label_12");

        gridLayout_2->addWidget(label_12, 11, 0, 1, 1);

        lowerLevelLineEdit = new QLineEdit(groupBox_3);
        lowerLevelLineEdit->setObjectName("lowerLevelLineEdit");

        gridLayout_2->addWidget(lowerLevelLineEdit, 8, 2, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 5, 0, 1, 1);

        midLevelCategoryComboBox = new QComboBox(groupBox_3);
        midLevelCategoryComboBox->setObjectName("midLevelCategoryComboBox");

        gridLayout_2->addWidget(midLevelCategoryComboBox, 7, 2, 1, 1);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName("label_11");

        gridLayout_2->addWidget(label_11, 10, 0, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName("label_9");

        gridLayout_2->addWidget(label_9, 8, 0, 1, 1);

        descriptionTextEdit = new QTextEdit(groupBox_3);
        descriptionTextEdit->setObjectName("descriptionTextEdit");

        gridLayout_2->addWidget(descriptionTextEdit, 10, 2, 1, 1);

        priorityComboBox = new QComboBox(groupBox_3);
        priorityComboBox->setObjectName("priorityComboBox");

        gridLayout_2->addWidget(priorityComboBox, 5, 2, 1, 1);

        topLevelCategoryComboBox = new QComboBox(groupBox_3);
        topLevelCategoryComboBox->setObjectName("topLevelCategoryComboBox");

        gridLayout_2->addWidget(topLevelCategoryComboBox, 6, 2, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        attachmentPushButton = new QPushButton(groupBox_3);
        attachmentPushButton->setObjectName("attachmentPushButton");

        horizontalLayout_5->addWidget(attachmentPushButton);

        attachmentLabel = new QLabel(groupBox_3);
        attachmentLabel->setObjectName("attachmentLabel");

        horizontalLayout_5->addWidget(attachmentLabel);

        attachmentDeletePushButton = new QPushButton(groupBox_3);
        attachmentDeletePushButton->setObjectName("attachmentDeletePushButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/batsu"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        attachmentDeletePushButton->setIcon(icon);

        horizontalLayout_5->addWidget(attachmentDeletePushButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        gridLayout_2->addLayout(horizontalLayout_5, 11, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        addPushButton = new QPushButton(groupBox_3);
        addPushButton->setObjectName("addPushButton");

        horizontalLayout_3->addWidget(addPushButton);

        updatePushButton = new QPushButton(groupBox_3);
        updatePushButton->setObjectName("updatePushButton");

        horizontalLayout_3->addWidget(updatePushButton);

        clearPushButton = new QPushButton(groupBox_3);
        clearPushButton->setObjectName("clearPushButton");

        horizontalLayout_3->addWidget(clearPushButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout_4->addWidget(groupBox_3);

        IdeaDatabase->setCentralWidget(centralwidget);
        menubar = new QMenuBar(IdeaDatabase);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1093, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        IdeaDatabase->setMenuBar(menubar);
        statusbar = new QStatusBar(IdeaDatabase);
        statusbar->setObjectName("statusbar");
        IdeaDatabase->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionClose);
        menuFile->addAction(actionExport_to_JSON);
        menuFile->addAction(actionImport_JSON);
        menuFile->addAction(actionSettings);

        retranslateUi(IdeaDatabase);
        QObject::connect(actionSettings, SIGNAL(triggered(bool)), IdeaDatabase, SLOT(onSettingsClicked()));
        QObject::connect(recordTableView, SIGNAL(clicked(QModelIndex)), IdeaDatabase, SLOT(onRecordTableViewSelected(QModelIndex)));

        QMetaObject::connectSlotsByName(IdeaDatabase);
    } // setupUi

    void retranslateUi(QMainWindow *IdeaDatabase)
    {
        IdeaDatabase->setWindowTitle(QCoreApplication::translate("IdeaDatabase", "IdeaDatabase", nullptr));
        actionNew->setText(QCoreApplication::translate("IdeaDatabase", "New", nullptr));
        actionOpen->setText(QCoreApplication::translate("IdeaDatabase", "Open", nullptr));
        actionClose->setText(QCoreApplication::translate("IdeaDatabase", "Close", nullptr));
        actionExport_to_JSON->setText(QCoreApplication::translate("IdeaDatabase", "Export to JSON", nullptr));
        actionImport_JSON->setText(QCoreApplication::translate("IdeaDatabase", "Import JSON", nullptr));
        actionSettings->setText(QCoreApplication::translate("IdeaDatabase", "Settings", nullptr));
        groupBox->setTitle(QCoreApplication::translate("IdeaDatabase", "Category Tree View", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("IdeaDatabase", "List View", nullptr));
        searchPushButton->setText(QCoreApplication::translate("IdeaDatabase", "Search", nullptr));
        label_14->setText(QCoreApplication::translate("IdeaDatabase", "Top-Level Category", nullptr));
        label_13->setText(QCoreApplication::translate("IdeaDatabase", "Status", nullptr));
        label_15->setText(QCoreApplication::translate("IdeaDatabase", "Mid-Level Category", nullptr));
        label_16->setText(QCoreApplication::translate("IdeaDatabase", "Priority", nullptr));
        deletePushButton->setText(QCoreApplication::translate("IdeaDatabase", "Delete", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("IdeaDatabase", "Selection Field", nullptr));
        updateDateLabel->setText(QCoreApplication::translate("IdeaDatabase", "Update Date", nullptr));
        label_2->setText(QCoreApplication::translate("IdeaDatabase", "Update Date", nullptr));
        label_7->setText(QCoreApplication::translate("IdeaDatabase", "Top-Level Category", nullptr));
        label_8->setText(QCoreApplication::translate("IdeaDatabase", "Mid-Level Category", nullptr));
        idLabel->setText(QCoreApplication::translate("IdeaDatabase", "ID Number", nullptr));
        label_3->setText(QCoreApplication::translate("IdeaDatabase", "Status", nullptr));
        label_10->setText(QCoreApplication::translate("IdeaDatabase", "Title", nullptr));
        label_5->setText(QCoreApplication::translate("IdeaDatabase", "Applied Section", nullptr));
        label_12->setText(QCoreApplication::translate("IdeaDatabase", "Attachment", nullptr));
        label->setText(QCoreApplication::translate("IdeaDatabase", "ID", nullptr));
        label_4->setText(QCoreApplication::translate("IdeaDatabase", "Date Applied", nullptr));
        label_6->setText(QCoreApplication::translate("IdeaDatabase", "Priority", nullptr));
        label_11->setText(QCoreApplication::translate("IdeaDatabase", "Description", nullptr));
        label_9->setText(QCoreApplication::translate("IdeaDatabase", "Lower-Level Category", nullptr));
        attachmentPushButton->setText(QCoreApplication::translate("IdeaDatabase", "Attachment", nullptr));
        attachmentLabel->setText(QString());
        attachmentDeletePushButton->setText(QString());
        addPushButton->setText(QCoreApplication::translate("IdeaDatabase", "Add", nullptr));
        updatePushButton->setText(QCoreApplication::translate("IdeaDatabase", "Update", nullptr));
        clearPushButton->setText(QCoreApplication::translate("IdeaDatabase", "Clear", nullptr));
        menuFile->setTitle(QCoreApplication::translate("IdeaDatabase", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IdeaDatabase: public Ui_IdeaDatabase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDEADATABASE_H
