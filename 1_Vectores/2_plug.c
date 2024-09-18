#include <stdio.h>

int main(int argc, char *argv[]) {
    int a[5];
    int b[5];
    while (scanf("%d", &a[0]) != EOF) {
        int use = 0;
        for (int i = 1; i < 5; i++) {
            scanf("%d ", &a[i]);
        }
        for (int i = 0; i < 5; i++) {
            scanf("%d ", &b[i]);
            if (b[i] == a[i]) {
                use = 1;
            }
        }
        if (use == 1)
            printf("N\n");
        else
            printf("Y\n");
    }
    return 0;
}
