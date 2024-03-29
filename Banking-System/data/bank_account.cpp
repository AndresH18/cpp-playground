//
// Created by andre on 10/2/2024.
//

#include "bank_account.h"

namespace banking::data {
    bank_account::bank_account(const int balance) : balance_{balance} {
    }

    int bank_account::get_balance() const {
        return balance_;
    }
} // banking::data
