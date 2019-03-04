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

class Status
{
  public:
    int top, east, west, south, north, bottom;
    Status(int a, int b, int c, int d, int e, int f)
    {
        top = a;
        east = b;
        west = c;
        south = d;
        north = e;
        bottom = f;
    }
};

Status *curr = new Status(0, 0, 0, 0, 0, 0);
int board[21][21];

void transition(int cmd)
{
    Status *next;
    switch (cmd)
    {
    case 1: // EAST
        next = new Status(curr->west, curr->top, curr->bottom, curr->south, curr->north, curr->east);
        break;
    case 2: // WEST
        next = new Status(curr->east, curr->bottom, curr->top, curr->south, curr->north, curr->west);
        break;
    case 3: // NORTH
        next = new Status(curr->south, curr->east, curr->west, curr->bottom, curr->top, curr->north);
        break;
    case 4: // SOUTH
        next = new Status(curr->north, curr->east, curr->west, curr->top, curr->bottom, curr->south);
        break;
    }
    delete curr;
    curr = next;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Volumes/Data/GoogleDrive/Programming/PS/in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x, y, k;
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &board[i][j]);

    for (int i = 0; i < k; i++)
    {
        int cmd;
        scanf("%d", &cmd);

        switch (cmd)
        {
        case 1:
            if (y + 1 < m)
                y++;
            else
                continue;
            break;
        case 2:
            if (y - 1 >= 0)
                y--;
            else
                continue;
            break;
        case 3:
            if (x - 1 >= 0)
                x--;
            else
                continue;
            break;
        case 4:
            if (x + 1 < n)
                x++;
            else
                continue;
        }
        transition(cmd);
        if (board[x][y] == 0)
            board[x][y] = curr->bottom;
        else
        {
            curr->bottom = board[x][y];
            board[x][y] = 0;
        }
        printf("%d\n", curr->top);
    }
}