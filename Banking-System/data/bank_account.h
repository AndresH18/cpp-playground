//
// Created by andre on 10/2/2024.
//

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <memory>


namespace banking::data {
    class bank_account {
        int balance_{0};

    public:
        explicit bank_account(int balance);

        explicit bank_account() = default;


        [[nodiscard]] int get_balance() const;
    };
} // banking::data

#endif //BANK_ACCOUNT_H
