#include <cstdio>

int state[101][101];
int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            char c;
            scanf("%c", &c);
            if(c == '.') state[i][j] = 0;
            else if(c == 'X') state[i][j] = 1;
            else { j--; continue; }
        }
    }

    int garo = 0, sero = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(state[i][j] == 0) cnt++;
            if(state[i][j] == 1)
            {
                if(cnt >= 2) garo++;
                cnt = 0;
            }
        }
        if(cnt >= 2) garo++;
        cnt = 0;
    }

    cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(state[j][i] == 0) cnt++;
            if(state[j][i] == 1)
            {
                if(cnt >= 2) sero++;
                cnt = 0;
            }
        }
        if(cnt >= 2) sero++;
        cnt = 0;
    }

    printf("%d %d", garo, sero);
}
