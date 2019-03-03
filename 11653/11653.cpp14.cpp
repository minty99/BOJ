#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <bitset>
using namespace std;

bitset<10000001> bs;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> sosu;
    bs.reset();
    for(int i = 2; i <= 10000000; i += ((i%2 == 0) ? 1 : 2))
    {
        for(int j = i*2; j <= 10000000; j += i) bs[j] = true;
    }

    sosu.push_back(2);
    for(int i = 3; i <= 10000000; i += 2)
        if(bs[i] == false) sosu.push_back(i);

    int p = 0;
    while(n > 1)
    {
        if(n % sosu[p] == 0) {
            printf("%d\n", sosu[p]);
            n /= sosu[p];
        }
        else p++;
    }
}