#ifndef TYPE_COMMOH_
#define TYPE_COMMON

#include "stdint.h"

// ID
typedef int8_t bank_id_t;      // bank ID
typedef int32_t card_id_t;     // card ID
typedef int32_t account_id_t;  // account ID

// PASSWORD
typedef uint64_t card_pin_t;         // 카드 비밀번호
typedef uint64_t account_password_t; // 계정 비밀번호

// CASH
typedef int64_t dollar;             // 달러 단위
#endif