//
// Created by andre on 11/2/2024.
//

#ifndef ACCOUNTS_ITEM_MODEL_H
#define ACCOUNTS_ITEM_MODEL_H

#include <vector>
#include <QAbstractListModel>

#include "data/bank_account.h"

using namespace banking::data;

class accounts_item_model : public QAbstractListModel {
    std::vector<std::shared_ptr<bank_account> > data_;

public:
    // explicit accounts_item_model(const std::vector<std::shared_ptr<bank_account> >& accounts);

    void set_accounts(const std::vector<std::shared_ptr<bank_account> >& accounts);

    const banking::data::bank_account& get_account(int index) const;

    int rowCount(const QModelIndex& parent) const override;

    QVariant data(const QModelIndex& index, int role) const override;
};


#endif //ACCOUNTS_ITEM_MODEL_H
