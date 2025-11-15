//ÃÖ´ñ°ª
#include <stdio.h>

int main(void) {
    int num;
    int max_val = 0;
    int max_index = 0;

    for (int i = 1; i <= 9; i++) {
        scanf("%d", &num);

        if (num > max_val) {
            max_val = num;
            max_index = i;
        }
    }

    printf("%d\n", max_val);
    printf("%d\n", max_index);

    return 0;
}