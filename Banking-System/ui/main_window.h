//
// Created by andre on 10/2/2024.
//

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>

namespace ui {
QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget {
Q_OBJECT

public:
    explicit main_window(QWidget *parent = nullptr);
    ~main_window() override;

private:
    Ui::main_window *ui;
};
} // ui

#endif //MAIN_WINDOW_H
