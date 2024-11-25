#ifndef ATM_PAHSE_H
#define ATM_PHASE_H
namespace atm {

enum class Phase {
  BANK_CHECK_DEPOSIT,
  BANK_DEPOSIT_PHASE,
  BANK_WITHDRAWL_PHASE,

  // 나중에 여기에 UI와 실제 동작을 한다
  USER_CASH_INPUT,
  USER_CASH_OUTPUT,
  MAX
};

} //namespace atm

#endif