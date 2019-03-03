#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

typedef pair<int, int> pii;
typedef long long lli;

#define HASH_NUM 300000

char pokemons[100001][21];
vector<int> hashtable[65536];

unsigned short power(unsigned short a, unsigned short exp)
{
    unsigned short ret = 1;
    while(exp > 0)
    {
        ret *= a;
        exp--;
    }
    return ret;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) scanf("%s", pokemons[i]);
    for(int i = 1; i <= n; i++)
    {
        unsigned short hash = 0;
        for(int j = 0; j < strlen(pokemons[i]); j++)
        {
            hash += (pokemons[i][j] * power(129, j));
        }
        hashtable[hash].push_back(i);
    }

    for(int i = 1; i <= m; i++)
    {
        char s[21];
        scanf("%s", s);
        if('0' <= s[0] && s[0] <= '9')
        {
            int q = atoi(s);
            printf("%s\n", pokemons[q]);
        }
        else
        {
            unsigned short hash = 0;
            for(int j = 0; s[j]; j++)
            {
                hash += (s[j] * power(129, j));
            }
            for(int j = 0; j < hashtable[hash].size(); j++)
            {
                if(!strcmp(s, pokemons[hashtable[hash][j]]))
                {
                    printf("%d\n", hashtable[hash][j]);
                    break;
                }
            }
        }
    }
}
