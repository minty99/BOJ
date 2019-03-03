#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int main()
{
    int n, k, dp = 0, ans = -1e9;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
		scanf("%d", &k);
		dp = max(dp + k, k);
		ans = max(ans, dp);
	}
    printf("%d", ans);
}
