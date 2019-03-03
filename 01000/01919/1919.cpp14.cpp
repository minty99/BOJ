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

int bs1[26], bs2[26];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    char s1[1200], s2[1200];
    scanf("%s", s1);
    scanf("%s", s2);
    string a(s1), b(s2);

    for(int i = 0; i < a.length(); i++) bs1[a[i] - 'a'] += 1;
    for(int i = 0; i < b.length(); i++) bs2[b[i] - 'a'] += 1;

    int ans = 0;
    for(int i = 0; i < 26; i++) ans += abs(bs1[i] - bs2[i]);
    printf("%d", ans);
}
