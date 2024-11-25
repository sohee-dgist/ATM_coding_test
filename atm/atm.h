#ifndef ATM_H_
#define ATM_H_

#include <cstdint>
#include "type_common.h"
#include <string>

namespace bank {
class Bank;
}

namespace card {
class Card;
}

namespace atm {
class Component;

enum class Mode {
    CHECK,
    DEPOSIT,
    WITHDRAWL,
    MAX
};

class ATM {
private:
    bank::Bank& bank_;

public:
    explicit ATM(bank::Bank& bank) : bank_(bank) {}
    ~ATM();
    bool PrepareSession(card_id_t card_id, card_pin_t pin);
    bool StartSession(account_id_t account_id, account_password_t password);

    bool SubmitCheckRequest(account_id_t account_id);
    bool SubmitDepositRequest(account_id_t account_id, dollar amount);
    bool SubmitWithdrawRequest(account_id_t account_id, dollar amount); // Check ATM First

private:
    void HandleResult(const std::string& result);
};
} // namespace atm
#endif
