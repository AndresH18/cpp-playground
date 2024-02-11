//
// Created by andre on 10/2/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include "main_window.h"
#include "ui_main_window.h"

namespace ui {
main_window::main_window(QWidget *parent) :
    QWidget(parent), ui(new Ui::main_window) {
    ui->setupUi(this);
}

main_window::~main_window() {
    delete ui;
}
} // ui
