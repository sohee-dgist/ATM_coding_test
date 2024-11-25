#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include "type_common.h"

namespace bank {

class Account {
private:
    account_id_t id_;
    account_password_t password_;
    dollar balance_;

    friend class Bank;
public:
    explicit Account (int id, account_password_t password, dollar balance) : id_(id), password_(password), balance_(balance) {}
private:
    dollar CheckBalance() const;
    bool Deposit(dollar amount);
    bool Withdraw(dollar amount);

    account_password_t get_password() const { return password_; }
};
}

#endif