#include <cstdio>
#include <iostream>
#include <cassert>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <bitset>
#include <random>
#define x first
#define y second
#define MOD 1000000007
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long int ulli;

int main()
{
    // freopen("in.txt", "r", stdin);

    int n = 0;
    while(true)
    {
        scanf("%d", &n);
        if(n == -1) break;

        int s = 0;
        vector<int> v;
        for(int i = 1; i <= n/2; i++)
        {
            if(n % i == 0)
            {
                s += i;
                v.push_back(i);
            }
        }
        printf("%d ", n);
        if(s == n)
        {
            printf("= %d", v[0]);
            for(int i = 1; i < v.size(); i++) printf(" + %d", v[i]);
        }
        else printf("is NOT perfect.");
        puts("");
    }

}
