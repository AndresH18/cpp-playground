//
// Created by andre on 10/2/2024.
//

#include "users_item_model.h"

#include <QString>


banking::data::user& users_item_model::get_user(const int index) {
    return users_[index];
}

int users_item_model::rowCount(const QModelIndex& parent) const {
    return users_.size();
}


QVariant users_item_model::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || index.row() > users_.size()) {
        return QVariant{};
    }
    if (role == Qt::DisplayRole) {
        QString name{QString::fromStdString(users_[index.row()].get_name())};

        return name;
    }
    return QVariant{};
}

void users_item_model::populate() {
    beginResetModel();
    users_.clear();
    users_.append(banking::data::user{"andres"});
    users_.append(banking::data::user{"david"});
    endResetModel();
}
