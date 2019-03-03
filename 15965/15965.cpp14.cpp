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

vector<int> sosu;

int main()
{
    // freopen("in.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    sosu.push_back(2);
    sosu.push_back(3);
    int s = 2;
    for(int i = 5; s <= n; i += 2)
    {
        for(int j = 1; j < s; j++)
        {
            if(sosu[j]*sosu[j] > i)
            {
                sosu.push_back(i);
                s++;
                break;
            }
            if(i % sosu[j] == 0) break;
        }
    }

    printf("%d", sosu[n-1]);
}
