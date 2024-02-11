//
// Created by andre on 10/2/2024.
//

#include "user.h"

#include <iostream>
#include <utility>

namespace banking::data {
    user::user(std::string name) : name_(std::move(name)) {
        for (int i = 0; i < 5; ++i) {
            // TODO: use random library instead of rand()
            accounts_.push_back(std::make_shared<bank_account>(rand()));
        }
    }

    const string& user::get_name() const {
        return name_;
    }

    void user::set_name(std::string name) {
        name_ = std::move(name);
    }

    void user::add_account(bank_account&& account) {
        accounts_.push_back(std::make_shared<bank_account>(account));
    }

    std::vector<shared_ptr<bank_account> >& user::get_accounts() {
        return accounts_;
    }
} // banking
