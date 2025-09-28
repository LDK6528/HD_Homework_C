//구구단: N을 입력받은 뒤, 구구단 N단을 출력하는 프로그램을 작성하시오. 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int N;

    scanf("%d", &N);

    for (int i = 1; i <= 9; i++) {

        printf("%d * %d = %d\n", N, i, N * i);
    }

    return 0;
}