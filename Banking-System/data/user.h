//
// Created by andre on 10/2/2024.
//

#ifndef USER_H
#define USER_H
#include <memory>
#include <vector>

#include "bank_account.h"


using namespace std;

namespace banking::data {
    class user {
        std::string name_;
        // TODO: convert to shared pointer of vector of unique pointers of bank account
        std::vector<shared_ptr<bank_account> > accounts_;

    public:
        explicit user(std::string name);

        [[nodiscard]] const string& get_name() const;

        void set_name(std::string name);

        void add_account(bank_account&& account);

        std::vector<shared_ptr<bank_account>>& get_accounts();
    };
} // data
// banking

#endif //USER_H
