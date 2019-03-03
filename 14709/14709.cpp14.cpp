#include <stdio.h>
#include <vector>

int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    bool flag1, flag2, flag3;
    flag1 = flag2 = flag3 = false;
    for(int i = 1; i <= n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int x = a < b ? a : b;
        int y = a < b ? b : a;
        if(x == 1 && y == 3) flag1 = true;
        else if(x == 1 && y == 4) flag2 = true;
        else if(x == 3 && y == 4) flag3 = true;
        else
        {
            printf("Woof-meow-tweet-squeek");
            return 0;
        }
    }
    if(flag1 && flag2 && flag3) printf("Wa-pa-pa-pa-pa-pa-pow!");
    else printf("Woof-meow-tweet-squeek");
}
