#include <iostream>
#include <string>
#include "bank/bank.h"
#include "atm/atm.h"
#include "card/card.h"

int main() {
    std::cout << "Welcome to the ATM System!" << std::endl;

    // 1. Bank 만들기
    bank::Bank my_bank;

    // 2. ATM 만들기
    atm::ATM my_ATM(my_bank);

    // 상태 플래그
    bool card_issued = false;
    bool account_issued = false;
    bool atm_session_prepared = false;
    bool account_session_started = false;

    // 자동으로 설정되는 변수
    card_id_t current_card_id = 0;
    account_id_t current_account_id = 0;

    while (true) {
        std::cout << "\nOptions:\n"
                  << "1. Issue Card\n"
                  << "2. Issue Account\n"
                  << "3. Prepare ATM Session\n"
                  << "4. Start Account Session\n"
                  << "5. Check Balance\n"
                  << "6. Deposit\n"
                  << "7. Withdraw\n"
                  << "8. Exit\n"
                  << "Choose an option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // 카드 발급
                std::cout << "Enter PIN for the new card: ";
                card_pin_t pin;
                std::cin >> pin;
                auto card = my_bank.IssueCard(pin);
                current_card_id = card.get_card_id();  // 카드 ID 저장
                std::cout << "Issued card with ID: " << current_card_id << std::endl;
                card_issued = true;
                break;
            }
            case 2: {
                // 계좌 발급
                if (!card_issued) {
                    std::cout << "You must issue a card first (Option 1)." << std::endl;
                    break;
                }
                std::cout << "Enter Account Password: ";
                account_password_t password;
                std::cin >> password;
                my_bank.IssueAccount(current_card_id, password);
                current_account_id = 1;  // 계좌 ID 저장 (단일 계좌로 가정)
                std::cout << "Issued account with ID: " << current_account_id << std::endl;
                account_issued = true;
                break;
            }
            case 3: {
                // ATM 세션 준비
                if (!card_issued) {
                    std::cout << "You must issue a card first (Option 1)." << std::endl;
                    break;
                }
                std::cout << "Enter PIN: ";
                card_pin_t pin;
                std::cin >> pin;
                if (my_ATM.PrepareSession(current_card_id, pin)) {
                    std::cout << "ATM session prepared successfully!" << std::endl;
                    atm_session_prepared = true;
                } else {
                    std::cout << "Failed to prepare ATM session!" << std::endl;
                }
                break;
            }
            case 4: {
                // 계좌 세션 시작
                if (!account_issued || !atm_session_prepared) {
                    std::cout << "You must issue an account (Option 2) and prepare an ATM session (Option 3) first." << std::endl;
                    break;
                }
                std::cout << "Enter Account Password: ";
                account_password_t password;
                std::cin >> password;
                if (my_ATM.StartSession(current_account_id, password)) {
                    std::cout << "Session started successfully!" << std::endl;
                    account_session_started = true;
                } else {
                    std::cout << "Failed to start session!" << std::endl;
                }
                break;
            }
            case 5: {
                // 잔액 확인
                if (!account_session_started) {
                    std::cout << "You must complete Options 1, 2, 3, and 4 first." << std::endl;
                    break;
                }
                my_ATM.SubmitCheckRequest(current_account_id);
                break;
            }
            case 6: {
                // 입금
                if (!account_session_started) {
                    std::cout << "You must complete Options 1, 2, 3, and 4 first." << std::endl;
                    break;
                }
                std::cout << "Enter Amount to Deposit: ";
                dollar amount;
                std::cin >> amount;
                my_ATM.SubmitDepositRequest(current_account_id, amount);
                break;
            }
            case 7: {
                // 출금
                if (!account_session_started) {
                    std::cout << "You must complete Options 1, 2, 3, and 4 first." << std::endl;
                    break;
                }
                std::cout << "Enter Amount to Withdraw: ";
                dollar amount;
                std::cin >> amount;
                my_ATM.SubmitWithdrawRequest(current_account_id, amount);
                break;
            }
            case 8: {
                // 종료
                std::cout << "Thank you for using the ATM System!" << std::endl;
                return 0;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
    }

    return 0;
}
