//Çà·Ä µ¡¼À
#include <stdio.h>

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    int A[100][100];
    int B_val;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &B_val);
            printf("%d ", A[i][j] + B_val);
        }
        printf("\n");
    }

    return 0;
}