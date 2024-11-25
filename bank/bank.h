#ifndef BANK_H_
#define BANK_H_
#include <iostream>
#include <unordered_map>
#include <set>
#include <type_common.h>
#include <functional>
#include <queue>

namespace card{
class Card;
}

namespace bank {

class Account;

enum class EventType {
    VerifyCard,
    VerifyAccount,
    Deposit,
    Withdraw,
    CheckBalance
};

struct Event {
    EventType type;
    // for card verify
    card_pin_t card_id;
    card_id_t card_pin;
    // for account verify
    account_id_t account_id;
    account_password_t password;
    // for check, withdraw, deposit
    dollar amount;

    std::function<void(const std::string&)> callback;
    std::function<void(const bool)> callback2;
};

class Bank{
private:
    std::unordered_map<card_id_t, card_pin_t> card_and_passwords_;
    std::unordered_map<card_id_t, account_id_t> card_id_to_accounts_;
    std::unordered_map<account_id_t, Account> account_id_to_accounts_;

    std::queue<Event> event_queue_;
    void ProcessEvent(const Event& event);

public:
    Bank() = default;
    ~Bank() = default;

    card::Card *IssueCard(card_pin_t pin);
    Account *IssueAccount(card_id_t card_id, account_password_t password);

    void SubmitEvent(const Event& event);
    void ProcessAllEvents();
private:

};

} // namespace bank
#endif
