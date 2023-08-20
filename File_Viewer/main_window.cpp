//
// Created by andre on 20/8/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Main_Window.h" resolved

#include "main_window.h"
#include "ui_Main_Window.h"


Main_Window::Main_Window(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::Main_Window) {
    ui->setupUi(this);
}

Main_Window::~Main_Window() {
    delete ui;
}
