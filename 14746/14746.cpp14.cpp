#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <random>
#include <array>
#define x first
#define y second
#define MOD 1000000007
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long int ulli;

vector<int> v1, v2;

int main()
{
    // freopen("in.txt", "r", stdin);
    int n, m, c1, c2;
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    v1.resize(n);
    v2.resize(m);
    for(int i = 0; i < n; i++) scanf("%d", &v1[i]);
    for(int i = 0; i < m; i++) scanf("%d", &v2[i]);

    // O(nlogn) + O(n)
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int j = 0;  // v2[j]: v1[i]보다 작은 것 중 최대
    int mi = 2e9;
    int cnt = 0;
    // i: index in v1
    for(int i = 0; i < n; i++)
    {
        while(j+1 < m-1 and v2[j+1] < v1[i]) j++;
        if(j+1 < m)
        {
            int d1 = abs(c2-c1) + abs(v2[j+1]-v1[i]);
            if(d1 == mi) cnt++;
            if(d1 < mi) { mi = d1; cnt = 1; }
        }

        int d2 = abs(c2-c1) + abs(v2[j]-v1[i]);
        if(d2 == mi) cnt++;
        if(d2 < mi) { mi = d2; cnt = 1; }
    }

    printf("%d %d", mi, cnt);
}
