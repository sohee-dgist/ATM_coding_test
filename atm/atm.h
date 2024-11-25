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

public:
    ATM(bank::Bank& bank);
    ~ATM();
    void StartSession();
    void EndSession();


    // void ATM::insert_card(const card::Card& card);
    // void ATM::enter_pin(const card_pin_t& pin);
private:
    void MakeComponentForCheck();
    void MakeComponentForDeposit();
    void MakeComponentForWithdrawl();

    template <typename T>
    void AddComponent(int *component_index);

};
} // namespace atm
#endif
