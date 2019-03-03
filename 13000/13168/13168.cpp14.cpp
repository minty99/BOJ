#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
typedef pair<int, int> pii;
typedef long long lli;

int n, r, m, k;
string city[110];
vector<int> travel;
lli v1[110][110];
lli v2[110][110];
lli cost[110][110];

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &r);
    char t[30];
    for(int i = 1; i <= n; i++)
    {
        scanf("%s", t);
        city[i] = string(t);
    }

    scanf("%d", &m);
    int st = 0, en = 0;
    for(int i = 1; i <= m; i++)
    {
        scanf("%s", t);
        string ss = t;

        for(int j = 1; j <= n; j++)
        {
            if(city[j] == ss)
            {
                if(i == 1) st = j;
                if(i == m) en = j;
                if(i != m) travel.push_back(j);
                break;
            }
        }
        if(i == m)
        {
            ss += "_end";
            city[n+1] = ss;
            travel.push_back(en);
        }
    }
    scanf("%d", &k);
    char s[30], e[30];
    lli c;
    for(int i = 1; i <= k; i++)
    {
        scanf("%s %s %s %lld", t, s, e, &c);
        string tt = t;
        int type;
        if(tt == "Mugunghwa" || tt == "ITX-Saemaeul" || tt == "ITX-Cheongchun")
            type = 1;
        else if(tt == "S-Train" || tt == "V-Train") type = 2;
        else type = 3;

        int ss, ee;
        for(int j = 1; j <= n+1; j++)
        {
            if(city[j] == s) ss = j;
            if(city[j] == e) ee = j;
        }
        if(v1[ss][ee] == 0) v1[ss][ee] = v1[ee][ss] = 1e9 + 7;
        if(v2[ss][ee] == 0) v2[ss][ee] = v2[ee][ss] = 1e9 + 7;
        if(ee == en) v1[ss][en] = v2[ss][en] = 1e9 + 7;
        v1[ss][ee] = min(v1[ss][ee], c);
        v1[ee][ss] = min(v1[ee][ss], c);
        if(ee == en) v1[ss][en] = min(v1[ss][en], c);

        if(c / 2 == 0) type = 1;
        if(type == 1)
        {
            v2[ss][ee] = -1;
            v2[ee][ss] = -1;
            if(ee == en) v2[ss][en] = -1;
        }
        else if(type == 2)
        {
            v2[ss][ee] = min(v2[ss][ee], c/2);
            v2[ee][ss] = min(v2[ee][ss], c/2);
            if(ee == en) v2[ss][en] = min(v2[ss][en], c/2);
        }
        else
        {
            v2[ss][ee] = min(v2[ss][ee], c);
            v2[ee][ss] = min(v2[ee][ss], c);
            if(ee == en) v2[ss][en] = min(v2[ss][en], c);
        }
    }

    // NO Naeilro ticket
    for(int i = 1; i <= n+1; i++)
    {
        for(int j = 1; j <= n+1; j++)
        {
            if(cost[i][j] == 0) cost[i][j] = 1e9 + 7;
            if(v1[i][j] == -1) cost[i][j] = 0;
            if(v1[i][j] > 0) cost[i][j] = min(cost[i][j], v1[i][j]);
            else if(i == j) cost[i][j] = 0;
            // printf("cost[%d][%d] = %d\n", i, j, cost[i][j]);
        }
    }

    for(int k = 1; k <= n+1; k++)
        for(int i = 1; i <= n+1; i++)
            for(int j = 1; j <= n+1; j++)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

    int l = travel.size();
    lli noNaeilro = 0;
    for(int i = 0; i < l-1; i++)
    {
        noNaeilro += cost[travel[i]][travel[i+1]];
        // printf("cost added: %d\n", cost[travel[i]][travel[i+1]]);
    }

    // Using Naeilro ticket
    for(int i = 1; i <= n+1; i++)
    {
        for(int j = 1; j <= n+1; j++)
        {
            if(cost[i][j] == 0) cost[i][j] = 1e9 + 7;
            if(v2[i][j] == -1) cost[i][j] = 0;
            if(v2[i][j] > 0) cost[i][j] = min(cost[i][j], v2[i][j]);
            else if(i == j) cost[i][j] = 0;
            // printf("cost[%d][%d] = %d\n", i, j, cost[i][j]);
        }
    }

    for(int k = 1; k <= n+1; k++)
        for(int i = 1; i <= n+1; i++)
            for(int j = 1; j <= n+1; j++)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

    l = travel.size();
    lli useNaeilro = r;
    for(int i = 0; i < l-1; i++)
    {
        useNaeilro += cost[travel[i]][travel[i+1]];
        // printf("cost added: %d\n", cost[travel[i]][travel[i+1]]);
    }
    if(useNaeilro < noNaeilro) printf("Yes");
    else printf("No");
}
