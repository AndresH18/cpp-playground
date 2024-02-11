//
// Created by andre on 10/2/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include "main_window.h"
#include "ui_main_window.h"
#include "../users_item_model.h"

#include <iostream>
#include <sstream>
#include <QStringListModel>
#include <QListWidget>

namespace ui {
    main_window::main_window(QWidget* parent) : QWidget(parent), ui(new Ui::main_window) {
        ui->setupUi(this);
        ui->the_label->setText("My my hello. how are you");
        ui->the_label->adjustSize();

        users_model_ = new users_item_model{};
        accounts_model_ = new accounts_item_model{};
        // QStringList* list = new QStringList;
        // *list << "Andres" << "hoyos";
        // QAbstractListModel* model_ = new QStringListModel{*list};
        ui->users_list_view->setModel(users_model_);
        ui->accounts_list_view->setModel(accounts_model_);
        users_model_->populate();

        connect(ui->users_list_view, &QListView::clicked, this, &main_window::users_list_selection_changed);
        connect(ui->accounts_list_view, &QListView::clicked, this, &main_window::accounts_list_selection_changed);
    }


    void main_window::users_list_selection_changed(const QModelIndex& index) {
        if (!index.isValid())
            return;

        const QVariant d = users_model_->data(index, Qt::DisplayRole);
        const QString s = d.value<QString>();
        std::cout << "user list item clicked, " << s.toStdString() << std::endl;

        std::ostringstream stream{};
        stream << "USER: " << s.toStdString();

        ui->the_label->setText(QString::fromStdString(stream.str()));

        accounts_model_->set_accounts(users_model_->get_user(index.row()).get_accounts());
    }

    void main_window::accounts_list_selection_changed(const QModelIndex& index) {
        if (!index.isValid())
            return;
        const auto usertIndex = ui->users_list_view->currentIndex();
        const auto& user = users_model_->get_user(usertIndex.row());
        const auto& account = accounts_model_->get_account(index.row());
        std::ostringstream stream{};

        stream << "USER: " << user.get_name() << "\n";
        stream << "ACCOUNT BALANCE: $" << account.get_balance() << endl;

        ui->the_label->setText(QString::fromStdString(stream.str()));
    }

    main_window::~main_window() {
        delete ui;
        delete users_model_;
        delete accounts_model_;
    }
} // ui
