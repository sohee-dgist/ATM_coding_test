#ifndef ATM_COMPONENT_H_
#define ATM_COMPONENT_H_
#include "phase.h"

namespace atm {

class ATM;

class Component {
protected:
    ATM *atm_{nullptr};
    Phase phase_{Phase::MAX};

public:
    explicit Component(ATM* atm, Phase phase) {
        atm_ = atm;
        phase_ = phase;
    }
    ~Component() = default;
    virtual void Execute() = 0;

    Phase phase() const { return phase_; }
    ATM *atm() const { return atm_; }
};

} // namespace atm
#endif