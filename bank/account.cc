#include "account.h"

namespace bank {
bool Account::Deposit(dollar amount) {
    balance_ += amount;
    return true;
}

// Withdraw money from an account
bool Account::Withdraw(dollar amount) {
    if (balance_ - amount < 0) {
        return false;
    }
    balance_ -= amount;
    return true;
}

// Check account balance
dollar Account::CheckBalance() const {
    return balance_;
}
} // namespace bank