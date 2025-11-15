//문자열 반복
#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int R;
        char S[21];

        scanf("%d %s", &R, S);

        for (int j = 0; S[j] != '\0'; j++) {
            for (int k = 0; k < R; k++) {
                printf("%c", S[j]);
            }
        }
        printf("\n");
    }

    return 0;
}