//
// Created by andre on 10/2/2024.
//

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>

#include "../accounts_item_model.h"
#include "../users_item_model.h"

namespace ui {
    QT_BEGIN_NAMESPACE

    namespace Ui {
        class main_window;
    }

    QT_END_NAMESPACE

    class main_window : public QWidget {
        Q_OBJECT

    public:
        explicit main_window(QWidget* parent = nullptr);

        ~main_window() override;

    private:
        Ui::main_window* ui;
        users_item_model* users_model_;
        accounts_item_model* accounts_model_;


    private slots:
        void users_list_selection_changed(const QModelIndex&);
        void accounts_list_selection_changed(const QModelIndex& index);
    };
} // ui

#endif //MAIN_WINDOW_H
