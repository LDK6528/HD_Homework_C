#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define FILENAME "accounts.txt"

typedef struct {
    char name[50];      // 계좌 소유자 이름
    double accountNumber;  // 계좌 번호
    double balance;     // 잔액
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

// 🔹 입력 버퍼 비우기 함수
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 🔹 계좌 정보 파일에서 불러오기
void loadAccounts() {
    FILE* file = fopen(FILENAME, "r");
    if (file == NULL) return;

    while (fscanf(file, "%s %lf %lf", accounts[account_count].name,
        &accounts[account_count].accountNumber,
        &accounts[account_count].balance) == 3) {
        account_count++;
    }
    fclose(file);
}

// 🔹 계좌 정보 파일에 저장
void saveAccounts() {
    FILE* file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("파일 저장 오류!\n");
        return;
    }
    for (int i = 0; i < account_count; i++) {
        fprintf(file, "%s %lf %.2lf\n", accounts[i].name,
            accounts[i].accountNumber, accounts[i].balance);
    }
    fclose(file);
}

// 🔹 계좌 개설
void createAccount() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("더 이상 계좌를 개설할 수 없습니다!\n");
        return;
    }

    printf("이름 입력: ");
    fgets(accounts[account_count].name, sizeof(accounts[account_count].name), stdin);
    accounts[account_count].name[strcspn(accounts[account_count].name, "\n")] = '\0'; // 개행 제거

    printf("계좌 번호 입력: ");
    scanf("%lf", &accounts[account_count].accountNumber);
    clearInputBuffer();

    printf("초기 입금액 입력: ");
    scanf("%lf", &accounts[account_count].balance);
    clearInputBuffer();

    account_count++;
    printf("계좌 개설 완료!\n");
}

// 🔹 특정 계좌 찾기
int findAccount(double accountNumber) {
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1;
}

// 🔹 입금
void deposit() {
    double accountNumber;
    int index;
    double amount;

    printf("입금할 계좌 번호 입력: ");
    scanf("%lf", &accountNumber);
    clearInputBuffer();

    index = findAccount(accountNumber);
    if (index == -1) {
        printf("존재하지 않는 계좌입니다!\n");
        return;
    }

    printf("입금할 금액 입력: ");
    scanf("%lf", &amount);
    clearInputBuffer();

    accounts[index].balance += amount;
    printf("입금 완료! 현재 잔액: %.2lf\n", accounts[index].balance);
}

// 🔹 출금
void withdraw() {
    int index;
    double amount, accountNumber;

    printf("출금할 계좌 번호 입력: ");
    scanf("%lf", &accountNumber);
    clearInputBuffer();

    index = findAccount(accountNumber);
    if (index == -1) {
        printf("존재하지 않는 계좌입니다!\n");
        return;
    }

    printf("출금할 금액 입력: ");
    scanf("%lf", &amount);
    clearInputBuffer();

    if (accounts[index].balance < amount) {
        printf("잔액 부족!\n");
        return;
    }

    accounts[index].balance -= amount;
    printf("출금 완료! 현재 잔액: %.2lf\n", accounts[index].balance);
}

// 🔹 계좌 정보 조회
void checkBalance() {
    double accountNumber;
    int index;

    printf("조회할 계좌 번호 입력: ");
    scanf("%lf", &accountNumber);
    clearInputBuffer();

    index = findAccount(accountNumber);
    if (index == -1) {
        printf("존재하지 않는 계좌입니다!\n");
        return;
    }

    printf("계좌 소유자: %s, 잔액: %.2lf\n", accounts[index].name, accounts[index].balance);
}

// 🔹 모든 계좌 목록 출력
void displayAccounts() {
    if (account_count == 0) {
        printf("등록된 계좌가 없습니다!\n");
        return;
    }

    printf("\n===== 계좌 목록 =====\n");
    for (int i = 0; i < account_count; i++) {
        printf("%d. 계좌 번호: %lf | 소유자: %s | 잔액: %.2lf\n",
            i + 1, accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

// 🔹 메인 함수
int main() {
    int choice;
    loadAccounts();

    while (1) {
        printf("\n===== 은행 시스템 =====\n");
        printf("1. 계좌 개설\n");
        printf("2. 입금\n");
        printf("3. 출금\n");
        printf("4. 계좌 조회\n");
        printf("5. 모든 계좌 목록\n");
        printf("6. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
        case 1:
            createAccount();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            checkBalance();
            break;
        case 5:
            displayAccounts();
            break;
        case 6:
            saveAccounts();
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 입력입니다.\n");
        }
    }
}
