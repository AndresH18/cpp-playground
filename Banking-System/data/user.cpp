//
// Created by andre on 10/2/2024.
//

#include "user.h"

#include <iostream>
#include <utility>

namespace banking::data {
    user::user(std::string name) : name_(std::move(name)) {
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
} // banking
