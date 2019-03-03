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

int a[51], orig[51];
bool comp(int a, int b) { return a < b; }
int idx[1001];

int main()
{
    // freopen("in.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        orig[i] = a[i];
    }
    sort(a, a+n, comp);
    idx[a[0]] = 0;
    for(int i = 1; i < n; i++)
    {
        if(a[i] != a[i-1]) idx[a[i]] = i;
    }

    int p[51];
    for(int i = 0; i < n; i++)
    {
        p[i] = idx[orig[i]];
        idx[orig[i]]++;
        printf("%d ", p[i]);
    }
}
