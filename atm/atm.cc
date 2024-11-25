#include "atm.h"
#include <cassert>
#include <iostream>
#include "component/component.h"

namespace atm {
void ATM::StartSession() {
    // 1) 카드 입력 받기 (구현할 수 없으므로 new 처리)
    // 2) 카드 PIN 번호 입력 받기
    // 3) 카드 PIN 번호 맞는지 체크하기
    // 4) 계좌 선택 받기
    // 5) Mode 선택 받기 
    // 6) component 만들기
}

void ATM::EndSession() {

}

void ATM::MakeComponentForCheck(){
    //잔액 조회
}

void ATM::MakeComponentForDeposit(){
    assert("not implemented yet");
}

void ATM::MakeComponentForWithdrawl(){
    //출금
    assert("not implemented yet");
}

template <typename T>
void ATM::AddComponent(int *component_index) {
  T* component = new T(this);
  components_.push_back(component);
  component_mapper_[component->phase()] = (*component_index)++;
}

} // namspace atm