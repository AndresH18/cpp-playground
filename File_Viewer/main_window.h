//
// Created by andre on 20/8/2023.
//

#ifndef FILE_VIEWER_MAIN_WINDOW_H
#define FILE_VIEWER_MAIN_WINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class Main_Window; }
QT_END_NAMESPACE

class Main_Window : public QMainWindow {
Q_OBJECT

public:
    explicit Main_Window(QWidget* parent = nullptr);

    ~Main_Window() override;

private:
    Ui::Main_Window* ui;
};


#endif //FILE_VIEWER_MAIN_WINDOW_H
