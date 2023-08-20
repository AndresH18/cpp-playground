//
// Created by andre on 20/8/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Main_Window.h" resolved

#include "main_window.h"
#include "ui_Main_Window.h"

#include <QStandardPaths>


Main_Window::Main_Window(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::Main_Window), p_fileSystemModel{nullptr} {
    ui->setupUi(this);

    QString rootPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

    p_fileSystemModel = new QFileSystemModel{};
    p_fileSystemModel->setRootPath(rootPath);

    ui->treeView->setModel(p_fileSystemModel);
    ui->treeView->setRootIndex(p_fileSystemModel->index(rootPath));
}

Main_Window::~Main_Window() {
    delete ui;
    delete p_fileSystemModel;
}
