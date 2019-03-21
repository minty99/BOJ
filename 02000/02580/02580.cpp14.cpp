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

int G[12][12];
bitset<10> chance[12][12];
auto comp = [](pii a, pii b) {
    return chance[a.first][a.second].count() < chance[b.first][b.second].count();
};

deque<pii> emptys;

pii get_square_start(int x, int y)
{
    return {(x - 1) / 3 * 3 + 1, (y - 1) / 3 * 3 + 1};
}

void calc_chance(int i, int j)
{
    if (G[i][j] == 0)
    {
        chance[i][j].set();
        for (int k = 1; k <= 9; k++)
            chance[i][j][G[i][k]] = chance[i][j][G[k][j]] = false;
        pii square_start = get_square_start(i, j);
        for (int k = square_start.first; k <= square_start.first + 2; k++)
        {
            for (int l = square_start.second; l <= square_start.second + 2; l++)
            {
                chance[i][j][G[k][l]] = false;
            }
        }
    }
}

inline int get_chance_count(pii p) { return chance[p.first][p.second].count(); }
inline bitset<10> get_chance(pii p) { return chance[p.first][p.second]; }
int get_decided_number(pii p)
{
    bitset<10> bs = get_chance(p);
    if (bs.count() > 1)
        return 0;
    for (int i = 1; i <= 9; i++)
        if (bs[i])
            return i;
    return 0;
}

void fill_emptys()
{
    emptys.clear();
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            if (G[i][j] == 0)
            {
                calc_chance(i, j);
                emptys.emplace_back(i, j);
            }

    sort(emptys.begin(), emptys.end(), comp);
}

void decide_trivial()
{
    if (!emptys.empty() && get_chance_count(emptys.front()) == 1)
    {
        G[emptys.front().first][emptys.front().second] = get_decided_number(emptys.front());
        emptys.pop_front();
    }
}

bool sudoku_solve();
bool sudoku_guess(pii p)
{
    auto bs = get_chance(p);
    int _G[10][10];
    for (int i = 1; i <= 9; i++)
    {
        if (bs[i])
        {
            for (int x = 1; x <= 9; x++)
                for (int y = 1; y <= 9; y++)
                    _G[x][y] = G[x][y];
            G[p.first][p.second] = i;
            bool success = sudoku_solve();
            if (success)
                return true;
            else
            {
                for (int x = 1; x <= 9; x++)
                    for (int y = 1; y <= 9; y++)
                        G[x][y] = _G[x][y];
            }
        }
    }
    return false;
}

bool sudoku_solve()
{
    int prev = -1;
    while (true)
    {
        fill_emptys();
        if (emptys.empty())
            return true;
        if (prev == emptys.size())
            return false;
        prev = emptys.size();
        if (get_chance_count(emptys.front()) >= 1)
            return sudoku_guess(emptys.front());
        else
            return false;
    }
}

void sudoku_print()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            printf("%d ", G[i][j]);
        }
        puts("");
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
        {
            scanf("%d", &G[i][j]);
            chance[i][j].set();
        }
    bool solved = sudoku_solve();
    sudoku_print();
}
