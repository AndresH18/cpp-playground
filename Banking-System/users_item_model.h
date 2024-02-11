//
// Created by andre on 10/2/2024.
//

#ifndef USERS_ITEM_MODEL_H
#define USERS_ITEM_MODEL_H

#include <QAbstractItemModel>

class users_item_model : public QAbstractItemModel {
public:
    int columnCount(const QModelIndex& parent) const override;
};


#endif //USERS_ITEM_MODEL_H
