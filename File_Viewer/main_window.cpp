
// You may need to build the project (run Qt uic code generator) to get "ui_Main_Window.h" resolved

#include "main_window.h"
#include "ui_Main_Window.h"

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStandardPaths>


Main_Window::Main_Window(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::Main_Window), p_fileSystemModel{nullptr}, b_isEditted{false} {
    ui->setupUi(this);

    QString rootPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

    p_fileSystemModel = new QFileSystemModel{};
    p_fileSystemModel->setRootPath(rootPath);

    ui->treeView->setModel(p_fileSystemModel);
    ui->treeView->setRootIndex(p_fileSystemModel->index(rootPath));

    QObject::connect(ui->treeView, &QTreeView::activated, this, &Main_Window::fileSelected);
    QObject::connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, this, &Main_Window::textChanged);
}

void Main_Window::fileSelected(const QModelIndex& qModelIndex) {
    if (!qModelIndex.isValid())
        return;

    if (p_fileSystemModel && !(p_fileSystemModel->isDir(qModelIndex))) {
        QString filePath = p_fileSystemModel->filePath(qModelIndex);

        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);

        ui->plainTextEdit->clear();

        while (!in.atEnd()) {
            QString line = in.readLine();
            ui->plainTextEdit->appendPlainText(line);
        }

        file.close();

    }
}

void Main_Window::textChanged() {
    b_isEditted = true;
    ui->saveButton->setEnabled(true);
}

Main_Window::~Main_Window() {
    delete ui;
    delete p_fileSystemModel;
}
