#include <cstdio>
#include <vector>

using namespace std;
vector<int> bs(97);

int main()
{
    // freopen("in.txt", "r", stdin);

    int n, p;
    scanf("%d %d", &n, &p);

    int k = n;
    for(int i = 1; ; i++)
    {
        if(k <= 96)
        {
            if(bs[k] != 0) { printf("%d", i - bs[k]); break; }
            bs[k] = i;
        }
        k = (k*n) % p;
    }
}
