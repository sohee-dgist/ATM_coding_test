#include "atm.h"
#include <cassert>
#include <iostream>
#include <bank/bank.h>
#include <string>
namespace atm {

void ATM::HandleResult(const std::string& result) {
    std::cout << "ATM: " << result << std::endl;
}

bool ATM::PrepareSession(card_id_t card_id, card_pin_t pin) {
    bool success = false;
    bank_.SubmitEvent({
        bank::EventType::VerifyCard,
        card_id,
        pin,
        0,
        0,
        0,
        [this](const std::string& result) { this->HandleResult(result); },
        [&success](const bool is_success) {
            success = is_success;
        }
    });
    return success;
}

bool ATM::StartSession(account_id_t account_id, account_password_t password) {
    bool success = false;
    bank_.SubmitEvent({
        bank::EventType::VerifyAccount,
        0,
        0,
        account_id,
        password,
        0,
        [this](const std::string& result) { this->HandleResult(result); },
        [&success](const bool is_success) {
            success = is_success;
        }
    });
    return success;
}

bool ATM::SubmitCheckRequest(account_id_t account_id) {
    bool success = false;
    bank_.SubmitEvent({
        bank::EventType::CheckBalance,
        0,
        0,
        account_id,
        0,
        0,
        [this](const std::string& result) { this->HandleResult(result); },
        [&success](const bool is_success) {
            success = is_success;
        }
    });
    return success;
}

bool ATM::SubmitDepositRequest(account_id_t account_id, dollar amount) {
    bool success = false;
    bank_.SubmitEvent({
        bank::EventType::Deposit,
        0,
        0,
        account_id,
        0,
        amount,
        [this](const std::string& result) { this->HandleResult(result); },
        [&success](const bool is_success) {
            success = is_success;
        }
    });
    return success;
}

bool ATM::SubmitWithdrawRequest(account_id_t account_id, dollar amount) {
    bool success = false;
    bank_.SubmitEvent({
        bank::EventType::Withdraw,
        0,
        0,
        account_id,
        0,
        amount,
        [this](const std::string& result) { this->HandleResult(result); },
        [&success](const bool is_success) {
            success = is_success;
        }
    });
    return success;
}


} // namspace atm