//
// Created by andre on 10/2/2024.
//

#ifndef USERS_ITEM_MODEL_H
#define USERS_ITEM_MODEL_H

#include <QAbstractListModel>
#include <QList>

#include "data/user.h"

class users_item_model : public QAbstractListModel {
    QList<banking::data::user> users_;

public:
    users_item_model() = default;

    int rowCount(const QModelIndex& parent) const override;

    QVariant data(const QModelIndex& index, int role) const override;

    banking::data::user& get_user(int index);

    void populate();
};


#endif //USERS_ITEM_MODEL_H
