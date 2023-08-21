//
// Created by andre on 20/8/2023.
//

#ifndef FILE_VIEWER_MAIN_WINDOW_H
#define FILE_VIEWER_MAIN_WINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>

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
    QFileSystemModel* p_fileSystemModel;
    bool b_isEditted;

private slots:
    void fileSelected(const QModelIndex& qModelIndex);
    void textChanged();

};


#endif //FILE_VIEWER_MAIN_WINDOW_H
