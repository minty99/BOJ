#include <cstdio>
#include <cmath>

int p[1000001];
int main()
{
    // freopen("in.txt", "r", stdin);
    int k;
    scanf("%d", &k);
    int pn = 5;
    p[1] = 2;
    p[2] = 3;
    p[3] = 5;
    p[4] = 7;
    p[5] = 11;
    for(int i = 13; i <= k/2+1; i += 2)
    {
        p[++pn] = i;
        for(int j = 1; j <= pn-1; j++)
        {
            if(p[j] > sqrt(i)) break;
            if(i % p[j] == 0) { pn--; break; }
        }
    }

    int s = 0;
    for(int i = 1; i <= pn; i++)
    {
        while(k % p[i] == 0)
        {
            k /= p[i];
            s++;
        }
        if(k == 1) break;
    }

    if(s > 1) printf("%d", (int)log2(s-1)+1);
    else printf("0");
}
