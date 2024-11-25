#include "account.h"
#include <cassert>
namespace bank {
dollar Account::Deposit(dollar amount) {
    balance_ += amount;
    return balance_;
}

// Withdraw money from an account
dollar Account::Withdraw(dollar amount) {
    assert((balance_ - amount) > 0);
    balance_ -= amount;
    return balance_;
}

// Check account balance
dollar Account::CheckBalance() const {
    return balance_;
}
} // namespace bank