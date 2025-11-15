//문자/문자열이 아닌 것을 텍스트 파일에 쓰기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    // 입력받을 변수 선언
    char name[10]; // 이름 받을 문자열 변수
    int age;       // 나이 받을 정수형 변수

    // student.txt라는 파일을 쓰기모드로 열기
    FILE* fp = fopen("student.txt", "wt");

    // (참고) 이 코드에서는 파일 열기 오류 확인을 생략함

    // 키보드로 name과 age를 입력받아 student.txt에 3번 출력
    for (int i = 0; i < 3; i++)
    {
        printf("다음 순서로 입력 (name age): ");
        scanf("%s %d", name, &age);     // 키보드로부터 입력 받기
        getchar();                        // 버퍼에 남은 줄바꿈(\n) 소모
        fprintf(fp, "%s %d\n", name, age); // student.txt에 name, age를 서식 맞춰 출력
    }

    // fprintf는 숫자(age)도 텍스트 파일에 출력 가능함

    // student.txt파일과 연결 해제
    fclose(fp);
    return 0;
}