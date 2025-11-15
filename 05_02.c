/* 파일 읽기(=파일로 입력 받기) */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    // 파일에서 읽은 문자를 받을 변수 생성
    char ch;

    // 스트림 생성
    FILE* fp = fopen("C:/KHS_Code/C_VS2022/ch5/ex1/data.txt", "rt"); // "rt"(읽기) 모드로 파일 열기. "r"도 가능.

    // 파일을 못 읽어오면 뒤에서 파일 다룰 때 오류 남
    // >> 오류 검사하자!
    if (fp == NULL) { // 실패하면 NULL반환. 이걸로 오류 검사
        printf("Failed to open file"); // 파일 읽기 실패 오류 메시지 출력
        return -1; // 오류(-1) 표시하며 종료
    }

    // 3번 반복
    for (int i = 0; i < 3; i++) {
        ch = fgetc(fp); // fp 파일에서 문자 1개 읽어 ch에 저장
        printf("%c\n", ch); // ch 변수 값 출력 (줄바꿈 포함)
    }

    // 스트림 종료
    fclose(fp);

    return 0; // 정상 종료

}