# ATM_coding_test
# ATM 시스템 사용 안내

## 소개
ATM 시스템에 오신 것을 환영합니다!  
이 시스템은 카드 발급, 계좌 생성, 입출금, 잔액 확인 등 기본적인 ATM 기능을 시뮬레이션합니다.  
작업이 올바른 순서로 수행되도록 설계되었으며, 이를 통해 논리적 일관성을 유지합니다.

---

## 사용법

### 1. ATM 시스템 실행
프로그램을 실행하면 인터랙티브 메뉴가 표시됩니다. 원하는 작업을 선택하여 진행합니다.

```bash
./bin/atm_system
```

### 2. 메뉴 옵션

아래는 사용 가능한 메뉴 옵션 목록입니다:

| 옵션 | 설명                                                       | 선행 조건                                   |
|------|------------------------------------------------------------|--------------------------------------------|
| **1** | 카드 발급: PIN을 설정하여 새 카드를 생성합니다.             | 없음                                       |
| **2** | 계좌 발급: 발급된 카드와 연결된 새 계좌를 생성합니다.        | **카드가 먼저 발급되어야 함(옵션 1).**       |
| **3** | ATM 세션 준비: 카드 ID와 PIN으로 ATM 세션을 준비합니다.      | **카드가 먼저 발급되어야 함(옵션 1).**       |
| **4** | 계좌 세션 시작: 계좌를 위한 세션을 시작합니다.              | **계좌 발급(옵션 2) 및 ATM 세션 준비(옵션 3).** |
| **5** | 잔액 확인: 현재 계좌의 잔액을 확인합니다.                  | **옵션 1, 2, 3, 4가 완료되어야 함.**         |
| **6** | 입금: 현재 계좌에 금액을 입금합니다.                      | **옵션 1, 2, 3, 4가 완료되어야 함.**         |
| **7** | 출금: 현재 계좌에서 금액을 출금합니다.                    | **옵션 1, 2, 3, 4가 완료되어야 함.**         |
| **8** | 종료: ATM 시스템을 종료합니다.                             | 없음                                       |

---

## 단계별 가이드

### 1단계: 카드 발급
옵션 `1`을 선택하여 새 카드를 발급받습니다. PIN을 설정해야 합니다.

```plaintext
Choose an option: 1
Enter PIN for the new card: 1234
Issued card with ID: 1
```

### 2단계: 계좌 발급
옵션 `2`를 선택하여 계좌를 생성합니다. 카드 ID와 계좌 비밀번호를 설정해야 합니다.

```plaintext
Choose an option: 2
Enter Card ID: 1
Enter Account Password: 5678
Issued account with ID: 1
```

### 3단계: ATM 세션 준비
옵션 `3`을 선택하여 ATM 세션을 준비합니다. 카드 ID와 PIN을 입력해야 합니다.

```plaintext
Choose an option: 3
Enter Card ID: 1
Enter PIN: 1234
ATM session prepared successfully!
```

### 4단계: 계좌 세션 시작
옵션 `4`를 선택하여 계좌 세션을 시작합니다. 계좌 ID와 비밀번호를 입력해야 합니다.

```plaintext
Choose an option: 4
Enter Account ID: 1
Enter Account Password: 5678
Session started successfully!
```

### 5단계: 잔액 확인
옵션 `5`를 선택하여 현재 계좌의 잔액을 확인합니다.

```plaintext
Choose an option: 5
Balance for account 1 is 0.0.
```

### 6단계: 입금
옵션 `6`을 선택하여 금액을 입금합니다.

```plaintext
Choose an option: 6
Enter Amount to Deposit: 1000
Deposited 1000 to account 1.
```

### 7단계: 출금
옵션 `7`을 선택하여 금액을 출금합니다.

```plaintext
Choose an option: 7
Enter Amount to Withdraw: 500
Withdrawn 500 from account 1.
```

### 8단계: 종료
옵션 `8`을 선택하여 시스템을 종료합니다.

```plaintext
Choose an option: 8
Thank you for using the ATM System!
```

---

## `make` 명령어 설명

### 1. `make`란 무엇인가?
`make`는 소프트웨어 빌드를 자동화하기 위한 유틸리티입니다.  
`Makefile`에 정의된 규칙에 따라 코드를 컴파일하고 실행 파일을 생성합니다.

### 2. `make` 명령 실행
`make` 명령어를 사용하여 프로젝트를 빌드합니다. 아래와 같이 실행합니다:

```bash
make
```

### 3. 일반적인 규칙
- **`make`**: 기본적으로 프로젝트를 빌드합니다.
- **`make clean`**: 이전 빌드 결과를 제거합니다.

---

## 중요한 참고 사항
- 옵션 1, 2, 3, 4를 완료한 후에만 옵션 5, 6, 7을 사용할 수 있습니다.
- 잘못된 순서로 작업을 수행하려고 하면 오류 메시지가 표시됩니다.

#### 오류 예시:
```plaintext
Choose an option: 5
You must complete Options 1, 2, 3, and 4 first.
```

---

## 예제 흐름

1. **카드 발급 (옵션 1)**
2. **계좌 발급 (옵션 2)**
3. **ATM 세션 준비 (옵션 3)**
4. **계좌 세션 시작 (옵션 4)**
5. **잔액 확인 (옵션 5)**
6. **입금 (옵션 6)**
7. **출금 (옵션 7)**
8. **시스템 종료 (옵션 8)**
