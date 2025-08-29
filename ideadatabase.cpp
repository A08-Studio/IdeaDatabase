#include "ideadatabase.h"
#include "ui_ideadatabase.h"

#include <QTableView>
#include <QStandardItem>
#include "settingsdialog.h"
#include <QFile>

#include <QCoreApplication>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

const QString IdeaDatabase::ATTACHMENT_DIR_PATH =
    QDir::currentPath() + "/attachments/";



IdeaDatabase::IdeaDatabase(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IdeaDatabase)
    , s(new SettingsDialog(this))
    , id(0)
{
    ui->setupUi(this);

    connect(s, SIGNAL(changeCategoryValue()), SLOT(onLoadTopLevelCategory()));
    connect(s, SIGNAL(changeCategoryValue()), SLOT(onLoadMidLevelCategory()));

    initializeDatabase();

    // モデルを作成（4行×4列）
    model = new QStandardItemModel(0, HEADER_MAX);

    // ヘッダー設定
    model->setHorizontalHeaderLabels(QStringList() << tr("ID")
        << tr("Update Date") << tr("Status") << tr("Date Applied")
        << tr("Applied Section") << tr("Priority") << tr("Top-Level Category")
        << tr("Mid-Level Category") << tr("Lower-Level Category")
        << tr("Title") << tr("Description") << tr("Attachment"));
    ui->recordTableView->setModel(model);
    ui->recordTableView->verticalHeader()->setVisible(false);  // 行番号を非表示にする

    loadStatus();
    loadPriority();
    onLoadTopLevelCategory();
    onLoadMidLevelCategory();

    loadDatabase();
}

IdeaDatabase::~IdeaDatabase()
{
    delete ui;
}

void IdeaDatabase::on_addPushButton_clicked()
{
    addRow();
}


void IdeaDatabase::on_updatePushButton_clicked()
{
    updateRecord();
}


void IdeaDatabase::on_clearPushButton_clicked()
{
    ui->statusComboBox->setCurrentIndex(-1);  // ComboBox の選択をクリア
    ui->dateAppliedDateEdit->setSpecialValueText("Pending");
    ui->dateAppliedDateEdit->setDate(ui->dateAppliedDateEdit->minimumDate());
    ui->appliedSectionTextEdit->clear();  // テキスト内容を全削除
    ui->priorityComboBox->setCurrentIndex(-1);
    ui->topLevelCategoryComboBox->setCurrentIndex(-1);
    ui->midLevelCategoryComboBox->setCurrentIndex(-1);
    ui->lowerLevelLineEdit->clear();  // テキスト内容をすべて削除
    ui->titleLineEdit->clear();
    ui->descriptionTextEdit->clear();
    ui->attachmentLabel->clear();
}


void IdeaDatabase::on_deletePushButton_clicked()
{
    QModelIndexList selected = ui->recordTableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        return;
    }

    const int row = selected.first().row();
    const int id  = model->data(model->index(row, ID)).toInt(); // 一番左=ID列

    // 1) 先にDBレコードを削除（トランザクションは任意）
    QSqlDatabase db = QSqlDatabase::database();
    db.transaction();

    QSqlQuery query;
    query.prepare("DELETE FROM data_table WHERE id = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        db.rollback();
        QMessageBox::critical(this, tr("エラー"),
                              tr("レコード削除に失敗しました：%1").arg(query.lastError().text()));
        return;
    }
    db.commit();

    // 2) 付随する添付ディレクトリを削除（attachments/<id>/ を再帰削除）
    const QString dirPath = attachmentDirForId(id);
    QDir dir(dirPath);
    if (dir.exists()) {
        if (!dir.removeRecursively()) {
            // ここが失敗してもDB削除は完了済みなので、警告だけ出す
            QMessageBox::warning(this, tr("警告"),
                                 tr("添付フォルダの削除に失敗しました：%1").arg(dirPath));
        }
    }

    // 3) モデルから行を削除
    model->removeRow(row);
}


void IdeaDatabase::on_searchPushButton_clicked()
{

}

void IdeaDatabase::onSettingsClicked()
{
    s->exec();
}

void IdeaDatabase::onLoadTopLevelCategory()
{
    ui->topLevelCategoryComboBox->clear();
    ui->filterTopLevelCategoryComboBox->clear();

    QFile l;
    l.setFileName("TopLevelCategory.txt");
    if (!l.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&l);
    while (!in.atEnd()) {
        QString line = in.readLine();
        ui->topLevelCategoryComboBox->addItem(line);
        ui->filterTopLevelCategoryComboBox->addItem(line);
    }
}

void IdeaDatabase::onLoadMidLevelCategory()
{
    ui->midLevelCategoryComboBox->clear();
    ui->filterMidLevelCategoryComboBox->clear();

    QFile l;
    l.setFileName("MidLevelCategory.txt");
    if (!l.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&l);
    while (!in.atEnd()) {
        QString line = in.readLine();
        ui->midLevelCategoryComboBox->addItem(line);
        ui->filterMidLevelCategoryComboBox->addItem(line);
    }
}

void IdeaDatabase::onRecordTableViewSelected(QModelIndex index)
{
    // qDebug()<<"test";

    if (!index.isValid())
        return;

    QAbstractItemModel *model = ui->recordTableView->model();

    int row = index.row();  // 選択された行番号

    // 各カラムの値を取得（カラム番号はモデル定義に合わせて調整）
    QString id = model->index(row, ID).data().toString();
    QString updateDate = model->index(row, UPDATE_DATE).data().toString();
    QString status = model->index(row, STATUS).data().toString();
    QString dateApplied = model->index(row, DATE_APPLIED).data().toString();
    QString appliedSection = model->index(row, APPLIED_SECTION).data().toString();
    QString priority = model->index(row, PRIORITY).data().toString();
    QString topLevelCategory = model->index(row, TOP_LEVEL_CATEGORY).data().toString();
    QString midLevelCategory = model->index(row, MID_LEVEL_CATEGORY).data().toString();
    QString lowerLevelCategory = model->index(row, LOWER_LEVEL_CATEGORY).data().toString();
    QString title = model->index(row, TITLE).data().toString();
    QString description = model->index(row, DESCRIPTION).data().toString();
    QString attachment = model->index(row, ATTACHMENT).data().toString();

    // 対応するウィジェットに値を反映
    ui->idLabel->setText(id);
    ui->updateDateLabel->setText(updateDate);
    ui->statusComboBox->setCurrentText(status); // 文字列が一致する項目を選択

    // DateEdit（日付）
    QDate date = QDate::fromString(dateApplied, "yyyy-MM-dd");  // フォーマットは必要に応じて調整
    if (date.isValid()) {
        ui->dateAppliedDateEdit->setDate(date);
    } else {
        // 無効な日付が入っていた場合は、クリアやデフォルト日付を設定
        ui->dateAppliedDateEdit->setDate(ui->dateAppliedDateEdit->minimumDate());
    }

    ui->appliedSectionTextEdit->setPlainText(appliedSection);
    ui->priorityComboBox->setCurrentText(priority);
    ui->topLevelCategoryComboBox->setCurrentText(topLevelCategory);
    ui->midLevelCategoryComboBox->setCurrentText(midLevelCategory );
    ui->lowerLevelLineEdit->setText(lowerLevelCategory);
    ui->titleLineEdit->setText(title);
    ui->descriptionTextEdit->setPlainText(description);
    ui->attachmentLabel->setText(attachment);
}

void IdeaDatabase::loadStatus()
{
    QFile l;
    l.setFileName("Status.txt");
    if (!l.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&l);
    while (!in.atEnd()) {
        QString line = in.readLine();
        ui->statusComboBox->addItem(line);
        ui->filterStatusComboBox->addItem(line);
    }
}

void IdeaDatabase::loadPriority()
{
    QFile l;
    l.setFileName("Priority.txt");
    if (!l.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&l);
    while (!in.atEnd()) {
        QString line = in.readLine();
        ui->priorityComboBox->addItem(line);
        ui->filterPriorityComboBox->addItem(line);
    }
}

void IdeaDatabase::addRow()
{
    // 1) INSERT（添付は一旦空）
    QSqlQuery query;
    query.prepare("INSERT INTO data_table (update_date, status, date_applied,"
                  "applied_section, priority, top_level_category, mid_level_category,"
                  "lower_level_category, title, description, attachment_filepath)"
                  " VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

    const QString updateDate = QDate::currentDate().toString("yyyy-MM-dd");
    const QString status     = ui->statusComboBox->currentText();
    const QString dateApplied= ui->dateAppliedDateEdit->date().toString("yyyy-MM-dd");
    const QString appliedSec = ui->appliedSectionTextEdit->toPlainText();
    const QString priority   = ui->priorityComboBox->currentText();
    const QString topCat     = ui->topLevelCategoryComboBox->currentText();
    const QString midCat     = ui->midLevelCategoryComboBox->currentText();
    const QString lowCat     = ui->lowerLevelLineEdit->text();
    const QString title      = ui->titleLineEdit->text();
    const QString desc       = ui->descriptionTextEdit->toPlainText();
    const QString fileNameText = ui->attachmentLabel->text().trimmed();

    // バインド（attachment_filepath は一旦空）
    query.addBindValue(updateDate);
    query.addBindValue(status);
    query.addBindValue(dateApplied);
    query.addBindValue(appliedSec);
    query.addBindValue(priority);
    query.addBindValue(topCat);
    query.addBindValue(midCat);
    query.addBindValue(lowCat);
    query.addBindValue(title);
    query.addBindValue(desc);
    query.addBindValue("");  // 添付は後でUPDATEする

    if (!query.exec()) {
        QMessageBox::critical(this, tr("エラー"),
                              tr("追加に失敗しました: %1").arg(query.lastError().text()));
        return;
    }

    // 2) 新規IDを取得（SQLite）
    QVariant vId = query.lastInsertId();
    if (!vId.isValid()) {
        // フォールバック
        QSqlQuery q("SELECT last_insert_rowid()");
        q.next();
        vId = q.value(0);
    }
    const int newId = vId.toInt();

    // 3) 添付があれば <id> フォルダへコピーし、パスUPDATE
    QString fullDestPath;
    if (!fileNameText.isEmpty()) {
        if (!copyAttachmentFileToIdDir(newId, &fullDestPath, true)) {
            // コピー失敗: 添付なしとして続行（すでに空文字）
        } else {
            QSqlQuery uq;
            uq.prepare("UPDATE data_table SET attachment_filepath = ? WHERE id = ?");
            uq.addBindValue(fullDestPath);
            uq.addBindValue(newId);
            uq.exec();
        }
    }

    // 4) モデルへ反映（QTableViewはファイル名のみ表示）
    const int row = model->rowCount();
    model->setRowCount(row + 1);
    model->setItem(row, ID,               new QStandardItem(QString::number(newId)));
    model->setItem(row, UPDATE_DATE,      new QStandardItem(updateDate));
    model->setItem(row, STATUS,           new QStandardItem(status));
    model->setItem(row, DATE_APPLIED,     new QStandardItem(dateApplied));
    model->setItem(row, APPLIED_SECTION,  new QStandardItem(appliedSec));
    model->setItem(row, PRIORITY,         new QStandardItem(priority));
    model->setItem(row, TOP_LEVEL_CATEGORY,new QStandardItem(topCat));
    model->setItem(row, MID_LEVEL_CATEGORY,new QStandardItem(midCat));
    model->setItem(row, LOWER_LEVEL_CATEGORY,new QStandardItem(lowCat));
    model->setItem(row, TITLE,            new QStandardItem(title));
    model->setItem(row, DESCRIPTION,      new QStandardItem(desc));
    model->setItem(row, ATTACHMENT,       new QStandardItem(fileNameText)); // ファイル名のみ
}


void IdeaDatabase::updateRecord()
{
    // 選択取得
    auto *selectionModel = ui->recordTableView->selectionModel();
    QModelIndexList selectedRows = selectionModel->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, tr("警告"), tr("更新する行を選択してください。"));
        return;
    }
    const int row = selectedRows.first().row();
    const int id  = model->index(row, ID).data().toInt();

    // 旧フルパス
    QString oldFullPath;
    QSqlQuery q;
    q.prepare("SELECT attachment_filepath FROM data_table WHERE id = ?");
    q.addBindValue(id);
    if (q.exec() && q.next()) {
        oldFullPath = q.value(0).toString();
    }

    // 新ファイル名→新フルパス（idフォルダ）
    const QString newFileName = ui->attachmentLabel->text().trimmed();
    const QString newFullPath = newFileName.isEmpty()
                                    ? QString()
                                    : (attachmentDirForId(id) + newFileName);

    // ★差分削除（同名なら削除しない）
    if (!oldFullPath.isEmpty()) {
        const QString oldName = QFileInfo(oldFullPath).fileName();
        if (newFileName.isEmpty() || oldName != newFileName) {
            // 旧を削除
            if (QFile::exists(oldFullPath)) QFile::remove(oldFullPath);
            QDir d(QFileInfo(oldFullPath).absolutePath());
            if (d.exists() && d.isEmpty()) d.rmpath(d.path());
        }
        // 同名のときは削除しない（サイズ比較・上書きは後段で実施）
    }

    // ★同名でも「サイズが違えば上書き」するコピー
    QString pathForDb;  // DBに入れる最終フルパス
    if (!newFileName.isEmpty()) {
        if (!copyAttachmentFileToIdDir(id, &pathForDb, /*onlyIfDifferent=*/true)) {
            return; // 失敗
        }
        // ヘルパーはコピーをスキップした場合でも outFullPath に既存パスを返す
        if (pathForDb.isEmpty()) pathForDb = newFullPath;
    } else {
        pathForDb.clear(); // 無添付化
    }

    // UPDATE 準備
    QSqlQuery query;
    query.prepare("UPDATE data_table SET "
                  "update_date = ?, status = ?, date_applied = ?, applied_section = ?, "
                  "priority = ?, top_level_category = ?, mid_level_category = ?, "
                  "lower_level_category = ?, title = ?, description = ?, attachment_filepath = ? "
                  "WHERE id = ?");

    const QString updateDate = QDate::currentDate().toString("yyyy-MM-dd");

    query.addBindValue(updateDate);
    query.addBindValue(ui->statusComboBox->currentText());
    query.addBindValue(ui->dateAppliedDateEdit->date().toString("yyyy-MM-dd"));
    query.addBindValue(ui->appliedSectionTextEdit->toPlainText());
    query.addBindValue(ui->priorityComboBox->currentText());
    query.addBindValue(ui->topLevelCategoryComboBox->currentText());
    query.addBindValue(ui->midLevelCategoryComboBox->currentText());
    query.addBindValue(ui->lowerLevelLineEdit->text());
    query.addBindValue(ui->titleLineEdit->text());
    query.addBindValue(ui->descriptionTextEdit->toPlainText());
    query.addBindValue(pathForDb);  // ← ここを統一
    query.addBindValue(id);

    if (!query.exec()) {
        QMessageBox::critical(this, tr("エラー"),
                              tr("更新に失敗しました: %1").arg(query.lastError().text()));
        return;
    }

    // モデル反映（表示はファイル名のみ）
    model->setData(model->index(row, UPDATE_DATE), updateDate);
    model->setData(model->index(row, STATUS), ui->statusComboBox->currentText());
    model->setData(model->index(row, DATE_APPLIED), ui->dateAppliedDateEdit->date().toString("yyyy-MM-dd"));
    model->setData(model->index(row, APPLIED_SECTION), ui->appliedSectionTextEdit->toPlainText());
    model->setData(model->index(row, PRIORITY), ui->priorityComboBox->currentText());
    model->setData(model->index(row, TOP_LEVEL_CATEGORY), ui->topLevelCategoryComboBox->currentText());
    model->setData(model->index(row, MID_LEVEL_CATEGORY), ui->midLevelCategoryComboBox->currentText());
    model->setData(model->index(row, LOWER_LEVEL_CATEGORY), ui->lowerLevelLineEdit->text());
    model->setData(model->index(row, TITLE), ui->titleLineEdit->text());
    model->setData(model->index(row, DESCRIPTION), ui->descriptionTextEdit->toPlainText());
    model->setData(model->index(row, ATTACHMENT), newFileName);

    QMessageBox::information(this, tr("完了"), tr("レコードを更新しました。"));
}


int IdeaDatabase::getMaxId()
{
    QSqlQuery query;

    if (!query.exec("SELECT MAX(id) FROM data_table")) {
        return -1;
    }

    int maxId = -1;
    if (query.next()) {
        maxId = query.value(0).toInt(); // NULLの場合は0になることに注意
    }
    return maxId;
}


int IdeaDatabase::getId()
{
    id = getMaxId() + 1;    // データベースの最大IDの次から開始
    return id;
}

void IdeaDatabase::initializeDatabase()
{
    // SQLiteデータベースを追加
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("IdeaDatabase.db");  // ファイル名

    if (!db.open()) {
        qDebug() << "データベースを開けません:" << db.lastError().text();
        return;
    }

    QSqlQuery query;

    // テーブル作成
    query.exec("CREATE TABLE IF NOT EXISTS data_table ("
        "id INTEGER PRIMARY KEY NOT NULL,"
        "update_date DATETIME NOT NULL,"
        "status VARCHAR(45) NOT NULL,"
        "date_applied DATETIME NOT NULL,"
        "applied_section VARCHAR(255) NOT NULL,"
        "priority VARCHAR(45) NOT NULL,"
        "top_level_category VARCHAR(45) NOT NULL,"
        "mid_level_category VARCHAR(45) NOT NULL,"
        "lower_level_category VARCHAR(255) NOT NULL,"
        "title VARCHAR(255) NOT NULL,"
        "description VARCHAR(512) NOT NULL,"
        "attachment_filepath VARCHAR(512) NOT NULL)");
}

void IdeaDatabase::loadDatabase()
{
    QSqlQuery query;

    query.exec("SELECT id, update_date, status, date_applied, applied_section,"
        "priority, top_level_category, mid_level_category,"
        "lower_level_category, title, description, attachment_filepath"
        " FROM data_table");
    while (query.next()) {

        int row = model->rowCount();
        QString text;

        int id = query.value(0).toInt();
        QStandardItem *item0 = new QStandardItem(QString::number(id));
        model->setItem(row, 0, item0);

        QDateTime updateDate = query.value(1).toDateTime();
        text = updateDate.toString("yyyy-MM-dd");
        QStandardItem *item1 = new QStandardItem(text);
        model->setItem(row, 1, item1);

        QString status = query.value(2).toString();
        text = status;
        QStandardItem *item2 = new QStandardItem(text);
        model->setItem(row, 2, item2);

        QDateTime dateApplied = query.value(3).toDateTime();
        text = dateApplied.toString("yyyy-MM-dd");
        QStandardItem *item3 = new QStandardItem(text);
        model->setItem(row, 3, item3);

        QString appliedSection = query.value(4).toString();
        text = appliedSection;
        QStandardItem *item4 = new QStandardItem(text);
        model->setItem(row, 4, item4);

        QString priority = query.value(5).toString();
        text = priority;
        QStandardItem *item5 = new QStandardItem(text);
        model->setItem(row, 5, item5);

        QString topLevelCategory = query.value(6).toString();
        text = topLevelCategory;
        QStandardItem *item6 = new QStandardItem(text);
        model->setItem(row, 6, item6);

        QString midLevelCategory = query.value(7).toString();
        text = midLevelCategory;
        QStandardItem *item7 = new QStandardItem(text);
        model->setItem(row, 7, item7);

        QString lowerLevelCategory = query.value(8).toString();
        text = lowerLevelCategory;
        QStandardItem *item8 = new QStandardItem(text);
        model->setItem(row, 8, item8);

        QString title = query.value(9).toString();
        text = title;
        QStandardItem *item9 = new QStandardItem(text);
        model->setItem(row, 9, item9);

        QString description = query.value(10).toString();
        text = description;
        QStandardItem *item10 = new QStandardItem(text);
        model->setItem(row, 10, item10);

        QString attachmentFilepath = query.value(11).toString();
        QString fileNameOnly = QFileInfo(attachmentFilepath).fileName();
        QStandardItem *item11 = new QStandardItem(fileNameOnly);
        model->setItem(row, 11, item11);
    }
}




void IdeaDatabase::on_attachmentPushButton_clicked()
{
    sourcePath = QFileDialog::getOpenFileName(this,
                                                      tr("ファイルを選択"),
                                                      "",
                                                      tr("すべてのファイル (*)"));
    fileName = QFileInfo(sourcePath).fileName();  // 元ファイル名

    // 例：LineEditに保存パスを表示
    ui->attachmentLabel->setText(fileName);
}


bool IdeaDatabase::copyAttachmentFile()
{
    if (sourcePath.isEmpty()) {
        return true;  // コピー元が指定されていない場合は true
    }

    // コピー先パスの作成（例：アプリの作業フォルダにコピー）
    QString destPath = ATTACHMENT_DIR_PATH + fileName;

    // コピー先フォルダが存在しない場合は作成
    QDir().mkpath(QFileInfo(destPath).absolutePath());

    // コピー実行
    if (!QFile::copy(sourcePath, destPath)) {
        QMessageBox::critical(this, tr("エラー"), tr("ファイルのコピーに失敗しました。"));
        sourcePath.clear();  // 失敗時も初期化
        return false;   // コピー失敗
    }

    sourcePath.clear();  // 成功時も初期化

    return true;  // コピー成功
}


void IdeaDatabase::deleteAttachmentFile()
{
    // 選択行のチェック
    QItemSelectionModel *sel = ui->recordTableView->selectionModel();
    if (!sel || sel->selectedRows().isEmpty()) {
        return;
    }

    int row = sel->selectedRows().first().row();
    int recId = model->index(row, ID).data().toInt();

    // DBから attachment_filepath を取得
    QSqlQuery q;
    q.prepare("SELECT attachment_filepath FROM data_table WHERE id = ?");
    q.addBindValue(recId);

    if (!q.exec() || !q.next()) {
        return; // 読み込み失敗 or レコードなし
    }

    QString filePath = q.value(0).toString();
    if (filePath.isEmpty()) {
        return; // 添付がない
    }

    // ファイル削除
    if (QFile::exists(filePath)) {
        QFile::remove(filePath);
    }
}


QString IdeaDatabase::attachmentDirForId(int id) const
{
    return ATTACHMENT_DIR_PATH + QString::number(id) + "/";
}

// 変更版: onlyIfDifferent=true のとき、サイズが同じならコピーをスキップ
bool IdeaDatabase::copyAttachmentFileToIdDir(int id, QString* outFullPath, bool onlyIfDifferent /*=true*/)
{
    if (outFullPath) *outFullPath = QString();

    // 添付未指定は成功扱い
    if (sourcePath.isEmpty()) return true;

    const QString dir = attachmentDirForId(id);
    QDir().mkpath(dir);

    const QString destPath = dir + fileName;

    if (onlyIfDifferent && QFile::exists(destPath)) {
        QFileInfo srcInfo(sourcePath);
        QFileInfo dstInfo(destPath);
        if (srcInfo.exists() && dstInfo.exists() && srcInfo.size() == dstInfo.size()) {
            // サイズが同じ → コピー不要
            if (outFullPath) *outFullPath = destPath;
            sourcePath.clear();
            return true;
        }
        // サイズが違う → 上書きのため先に削除
        QFile::remove(destPath);
    }

    // 通常コピー（既存があれば念のため削除してから）
    if (QFile::exists(destPath)) QFile::remove(destPath);

    if (!QFile::copy(sourcePath, destPath)) {
        QMessageBox::critical(this, tr("エラー"), tr("ファイルのコピーに失敗しました。"));
        sourcePath.clear();
        return false;
    }

    sourcePath.clear();
    if (outFullPath) *outFullPath = destPath;
    return true;
}


void IdeaDatabase::on_attachmentDeletePushButton_clicked()
{
    sourcePath = "";
    fileName = "";  // 元ファイル名

    // 例：LineEditに保存パスを表示
    ui->attachmentLabel->setText(fileName);
}

