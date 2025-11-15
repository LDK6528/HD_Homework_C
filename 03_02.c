//¹®ÀÚ¿­
#include <stdio.h>
#include <string.h>

int main(void) {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        char str[1001];
        scanf("%s", str);

        int len = strlen(str);

        printf("%c%c\n", str[0], str[len - 1]);
    }

    return 0;
}