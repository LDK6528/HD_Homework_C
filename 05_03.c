//파일 복사 (feof함수 활용)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    FILE* org = fopen("input.txt", "rt"); // 원본 파일("input.txt") 읽기("rt") 모드로 열기
    FILE* copy = fopen("output.txt", "wt"); // 복사본 파일("output.txt") 쓰기("wt") 모드로 열기
    char str[20]; // 파일 내용 읽어올 변수 (문자열)

    if (org == NULL || copy == NULL) // 두 파일 중 하나라도 열기 실패했는지 체크
    {
        printf("Failed to open file"); // 파일 열기 실패 오류 메시지 출력
        return -1; // 오류(-1) 반환 후 종료
    }

    // input.txt에서 파일 읽어 output.txt에 쓰기
    while (fgets(str, sizeof(str), org) != NULL) { // org에서 한 줄(str 크기만큼) 읽어 str에 저장. (읽기 성공 시 반복)
        // fgets는 읽기 성공 시 str 주소 반환, 파일 끝(EOF)이나 오류 시 NULL 반환

        fputs(str, copy); // copy가 가리키는 파일(output.txt)에 str의 내용 쓰기
    }

    // 파일 복사 완료되면 성공 메시지 출력
    if (feof(org) != 0) // org 파일 포인터가 파일의 끝(EOF)에 도달했는지 검사
        printf("File copied successfully"); // 파일 끝까지 다 읽었으면 복사 성공
    else
        printf("Failed to copy file"); // (오류 등으로) 파일 끝까지 못 읽었으면 실패

    // org, copy에서 각각 input.txt, output.txt와 연결 끊기 (파일 닫기)
    fclose(org);
    fclose(copy);

    return 0; // 정상 종료(0)
}