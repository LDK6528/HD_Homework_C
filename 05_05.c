#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // 동적할당 관련 함수는 stdlib.h 헤더에 있음

int main(void)
{
    // int 변수를 가리키는 int형 포인터 동적 할당으로 만들기
    int* ptr1 = (int*)malloc(sizeof(int)); // int(4바이트) 공간 할당, 그 시작주소를 ptr1에 저장
    int* ptr2 = (int*)malloc(sizeof(int) * 3); // int*3(12바이트) 공간 할당, 그 시작주소를 ptr2에 저장

    // ptr1은 int형 변수 포인터 >> 그 내용에 정수 담기 가능
    *ptr1 = 20;

    // ptr2는 int형 변수 3개 담을 공간 포인터
    // >> 크기가 3인 int형 배열처럼 사용 가능 (구조 같음)
    for (int i = 0; i < 3; i++)
        ptr2[i] = i;

    // ptr1, ptr2가 가리키는 변수 내용 출력
    printf("%d\n", *ptr1);
    for (int i = 0; i < 3; i++)
        printf("%d ", ptr2[i]);

    // 더 이상 쓰지 않는 공간은 해제
    free(ptr1);
    free(ptr2);

    return 0;
}