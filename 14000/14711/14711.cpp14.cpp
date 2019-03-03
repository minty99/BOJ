#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

int game[1100][1100];
int n;

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    char s[1001];
    scanf("%s", s);
    for(int i = 1; i <= n; i++)
    {
        char c = s[i-1];
        if(c == '.') game[1][i] = 0;
        if(c == '#') game[1][i] = 1;
    }

    for(int i = 1; i <= n-1; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int t = game[i-1][j] + game[i][j-1] + game[i][j+1];
            game[i+1][j] = t%2;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            printf("%c", game[i][j] == 0 ? '.' : '#');
        }
        puts("");
    }
}
