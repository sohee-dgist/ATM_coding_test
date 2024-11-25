#include "bank.h"
#include <iostream>
#include "account.h"
#include <random>
#include "card/card.h"
namespace bank {

static int current_card_id = 1;
static int current_account_id = 1;

void Bank::SubmitEvent(const Event& event) {
    event_queue_.push(event);
}

void Bank::ProcessAllEvents() {
    while (!event_queue_.empty()) {
        Event event = event_queue_.front();
        event_queue_.pop();
        ProcessEvent(event);
    }
}

void Bank::ProcessEvent(const Event& event) {
    std::string result;
    bool result_success = true;
    switch (event.type) {
        case EventType::VerifyCard: {
            auto it = card_and_passwords_.find(event.card_id);

            if (it != card_and_passwords_.end() && it->second == event.card_pin) {
                result_success = true;
                result = "Card verified successfully.";
                auto account_it = card_id_to_accounts_.find(event.card_id);
                if (account_it != card_id_to_accounts_.end()) {
                    result += " Linked Account ID: " + std::to_string(account_it->second) + ".";
                } else {
                    result += " No account linked to this card.";
                }
            } else {
                result_success = false;
                result = "Card verification failed.";
            }

            break;
        }
        case EventType::VerifyAccount: {
            auto it = account_id_to_accounts_.find(event.account_id);
            if (it != account_id_to_accounts_.end() && it->second.get_password() == event.password) {
                result = "Account verified successfully.";
            } else {
                result = "Account verification failed.";
                result_success = false;
            }
            break;
        }
        case EventType::Deposit: {
            auto it = account_id_to_accounts_.find(event.account_id);
            if (it != account_id_to_accounts_.end()) {
                it->second.Deposit(event.amount);
                result = "Deposited " + std::to_string(event.amount) + " to account " +
                         std::to_string(event.account_id) + ".";
            } else {
                result = "Deposit failed: Account not found.";
                result_success = false;
            }
            break;
        }
        case EventType::Withdraw: {
            auto it = account_id_to_accounts_.find(event.account_id);
            if (it != account_id_to_accounts_.end()) {
                if (it->second.Withdraw(event.amount)) {
                    result = "Withdrawn " + std::to_string(event.amount) + " from account " +
                             std::to_string(event.account_id) + ".";
                } else {
                    result = "Withdrawal failed: Insufficient funds.";
                    result_success = false;
                }
            } else {
                result = "Withdrawal failed: Account not found.";
                result_success = false;
            }
            break;
        }
        case EventType::CheckBalance: {
            auto it = account_id_to_accounts_.find(event.account_id);
            if (it != account_id_to_accounts_.end()) {
                result = "Balance for account " + std::to_string(event.account_id) + " is " +
                         std::to_string(it->second.CheckBalance()) + ".";
            } else {
                result = "Balance check failed: Account not found.";
                result_success = false;
            }
            break;
        }
    }

    if (event.callback) {
        event.callback(result);
        event.callback2(result_success);
    }
}

card::Card Bank::IssueCard(card_pin_t pin) {
    card_id_t card_id = current_card_id++;
    card_and_passwords_[card_id] = pin;

    std::cout << "Bank: Issued card with ID " << card_id << " and PIN " << pin << std::endl;
    return card::Card(card_id);
}

void Bank::IssueAccount(card_id_t card_id, account_password_t password) {
    if (card_and_passwords_.find(card_id) == card_and_passwords_.end()) {
        std::cerr << "Bank: Cannot issue account. Card ID " << card_id << " not found." << std::endl;
    }

    account_id_t account_id = current_account_id++;


    card_id_to_accounts_[card_id] = account_id;

    account_id_to_accounts_.insert(
        {account_id, Account(account_id, password, 0)}
    );

    std::cout << "Bank: Issued account with ID " << account_id
              << " linked to card ID " << card_id
              << " and password " << password << std::endl;

}

}