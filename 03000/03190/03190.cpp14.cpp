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

int arr[110][110];
pii head = {1, 1}, tail = {1, 1};
int direction = 1;
pii move_to_direction[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
deque<pii> path;
int t = 0;
int n, k;

void fail(int t)
{
    printf("%d\n", t);
    exit(0);
}

void go()
{
    t++;
    head.first += move_to_direction[direction].first;
    head.second += move_to_direction[direction].second;
    path.emplace_back(head.first, head.second);
    if (head.first < 1 || head.first > n || head.second < 1 || head.second > n || arr[head.first][head.second] == 1)
        fail(t);

    if (arr[head.first][head.second] != 2)
        arr[tail.first][tail.second] = 0;

    if (arr[head.first][head.second] != 2)
    {
        arr[head.first][head.second] = 1;
        tail = path.front();
        path.pop_front();
    }
    else
        arr[head.first][head.second] = 1;
    // printf("t = %d, head = (%d, %d), tail = (%d, %d)\n", t, head.first, head.second, tail.first, tail.second);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    scanf("%d %d", &n, &k);

    for (int i = 0; i < k; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        arr[x][y] = 2; // Apple
    }

    int l;
    scanf("%d", &l);
    for (int i = 0; i < l; i++)
    {
        int x;
        char c;
        scanf("%d %c", &x, &c);
        while (t < x)
            go();
        if (c == 'L')
            direction--;
        if (c == 'D')
            direction++;
        if (direction < 0)
            direction += 4;
        if (direction >= 4)
            direction -= 4;
    }

    while (true)
        go();
}