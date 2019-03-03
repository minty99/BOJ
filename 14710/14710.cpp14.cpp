#include <stdio.h>

int main()
{
    // freopen("in.txt", "r", stdin);
    int t1, t2;
    scanf("%d %d", &t1, &t2);
    if(t1 % 30 == (double)t2 / 12) printf("O");
    else printf("X");
}
