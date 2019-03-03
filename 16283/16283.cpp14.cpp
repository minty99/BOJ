#include <cstdio>

int main() {
    int a, b, n, w;
    scanf("%d%d%d%d", &a, &b, &n, &w);

    int answer = -1;
    for(int i = 1; i <= n-1; i++) {
        if (a * i + b * (n - i) == w) {
            if (answer == -1) {
                answer = i;
            } else {
                printf("-1");
                return 0;
            }
        }
    }

    if (answer == -1) {
        printf("-1");
    } else {
        printf("%d %d", answer, n-answer);
    }
    return 0;
}