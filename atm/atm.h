#ifndef ATM_H_
#define ATM_H_

#include <cstdint>
#include <vector>
#include "type_common.h"
#include <unordered_map>

namespace string {
class string;
}

namespace bank {
class Bank;
class Account;
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
    int16_t cash_reserve_ = 0;
    std::vector<Component *> components_;
    std::unordered_map<int, int> component_mapper_;
    bank::Bank& bank_;

public:
    explicit ATM(bank::Bank& bank) : bank_(bank) {}
    ~ATM();
    void StartSession();
    void CloseSession();


    // void ATM::insert_card(const card::Card& card);
    // void ATM::enter_pin(const card_pin_t& pin);
private:

};
} // namespace atm
#endif
