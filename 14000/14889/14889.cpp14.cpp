#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tgmath.h>
#include <tuple>
#include <unistd.h>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> plli;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long int ulli;

int s[30][30];
int sum = 0;
int n;
int ans = 987654321;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &s[i][j]);
            sum += s[i][j];
        }

    vector<int> v;
    for (int i = 0; i < n / 2; i++)
        v.push_back(0);
    for (int i = 0; i < n / 2; i++)
        v.push_back(1);

    do
    {
        vector<int> selected;
        vector<int> not_selected;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 1)
                selected.push_back(i);
            if (v[i] == 0)
                not_selected.push_back(i);
        }
        int sel = 0, nsel = 0;
        for (int i = 0; i < n / 2; i++)
            for (int j = 0; j < n / 2; j++)
                sel += s[selected[i]][selected[j]];
        for (int i = 0; i < n / 2; i++)
            for (int j = 0; j < n / 2; j++)
                nsel += s[not_selected[i]][not_selected[j]];
        ans = min(ans, abs(sel - nsel));
    } while (next_permutation(v.begin(), v.end()));

    printf("%d\n", ans);
}