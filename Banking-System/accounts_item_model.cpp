//
// Created by andre on 11/2/2024.
//

#include "accounts_item_model.h"

#include <sstream>

void accounts_item_model::set_accounts(const std::vector<std::shared_ptr<bank_account> >& accounts) {
    beginResetModel();
    data_ = accounts;
    endResetModel();
}

const banking::data::bank_account& accounts_item_model::get_account(const int index) const {
    return *data_[index];
}

int accounts_item_model::rowCount(const QModelIndex& parent) const {
    return data_.size();
}

QVariant accounts_item_model::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || index.row() > data_.size()) {
        return QVariant{};
    }
    if (role == Qt::DisplayRole) {
        const auto balance{data_[index.row()]->get_balance()};
        std::ostringstream format{};
        format << "$ " << balance;
        return QString::fromStdString(format.str());
    }
    return QVariant{};
}
