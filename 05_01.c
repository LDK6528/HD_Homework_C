#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    // 스트림 생성
    FILE* fp = fopen("data.txt", "wt"); // "data.txt" 쓰기 모드("wt" or "w")로 열기. 없으면 생성.

    // 성공 시 파일 위치 반환, 실패 시 NULL 반환

    // 파일 열기 실패하면 fputc에서 오류 남
    // >> 오류 검사 필요
    if (fp == NULL) { // fp가 NULL인지 검사 (실패 검사)
        printf("Failed to open file"); // 실패 메시지 출력
        // >> 오류 원인 파악용

        return -1; // 오류(-1) 반환 후 종료
        // -1은 비정상 종료 의미
    }

    fputc('A', fp); // 'A' 문자를 fp 파일에 쓰기
    fputc('B', fp);
    fputc('C', fp); // 'C' 쓰기. (문자열은 fputs)

    // 스트림 종료
    fclose(fp);
    return 0; // 정상 종료(0) 반환
}