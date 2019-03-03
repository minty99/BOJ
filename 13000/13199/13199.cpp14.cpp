#include <stdio.h>

int main()
{
    // freopen("in.txt", "r", stdin);
    int t, p, m, f, c;
    scanf("%d", &t);

    for(int z = 1; z <= t; z++)
    {
        scanf("%d %d %d %d", &p, &m, &f, &c);
        int chicken = 0;
        long long coupons =  (m / p * c / f) * c + (m / p * c) % f;
        while(coupons >= f)
        {
            chicken++;
            coupons += c;
            coupons -= f;
        }
        printf("%d\n", chicken);
    }
}
