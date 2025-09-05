#ifndef IDEADATABASE_H
#define IDEADATABASE_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QSqlDatabase>
#include <QSortFilterProxyModel>
#include <QHash>

QT_BEGIN_NAMESPACE
namespace Ui {
class IdeaDatabase;
}
QT_END_NAMESPACE

class SettingsDialog;

class MultiExactProxy : public QSortFilterProxyModel {
    Q_OBJECT

public:
    explicit MultiExactProxy(QObject *parent=nullptr);
    void setExact(int column, const QString &value);
    void setRoleForCompare(int role);
    void setCaseSensitivity(Qt::CaseSensitivity cs);

protected:
    bool filterAcceptsRow(int srcRow, const QModelIndex &srcParent) const override;

private:
    QHash<int, QString> m_exact;
    Qt::CaseSensitivity m_case = Qt::CaseInsensitive;
};


class IdeaDatabase : public QMainWindow
{
    Q_OBJECT

public:
    IdeaDatabase(QWidget *parent = nullptr);
    ~IdeaDatabase();

private slots:
    void on_addPushButton_clicked();

    void on_updatePushButton_clicked();

    void on_clearPushButton_clicked();

    void on_deletePushButton_clicked();

    void on_searchPushButton_clicked();

    void onSettingsClicked();

    void onLoadTopLevelCategory();

    void onLoadMidLevelCategory();

    void onRecordTableViewSelected(QModelIndex index);

    void on_attachmentPushButton_clicked();

    void on_attachmentDeletePushButton_clicked();

    void on_calendarPushButton_clicked();

private:
    enum Header {
        ID,
        UPDATE_DATE,
        STATUS,
        DATE_APPLIED,
        APPLIED_SECTION,
        PRIORITY,
        TOP_LEVEL_CATEGORY,
        MID_LEVEL_CATEGORY,
        LOWER_LEVEL_CATEGORY,
        TITLE,
        DESCRIPTION,
        ATTACHMENT,
        HEADER_MAX
    };
    void loadStatus();
    void loadPriority();
    void addRow();
    int getId();
    void initializeDatabase();
    void loadDatabase();
    int getMaxId();
    void updateRecord();
    bool copyAttachmentFile();
    void deleteAttachmentFile();
    QString attachmentDirForId(int id) const;
    bool copyAttachmentFileToIdDir(int id, QString* outFullPath,
                                   bool onlyIfDifferent /*=true*/);
    static const QString ATTACHMENT_DIR_PATH;
    Ui::IdeaDatabase *ui;
    QStandardItemModel *model;
    MultiExactProxy *proxyModel;
    SettingsDialog* s;
    int id;
    QSqlDatabase db;
    QString sourcePath;
    QString fileName;
};

#endif // IDEADATABASE_H
