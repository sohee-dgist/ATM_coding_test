#ifdef CARD_H_
#define CARD_H_

#include "type_common.h"

namespace card
class Card {
public:
  card_id_t get_card_id() { return card_id_; }
private:
  card_id_t card_id_;
}

#endif