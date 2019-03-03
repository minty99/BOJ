#include <cstdio>
#include <cstring>
using namespace std;

int m[100][100];
int answer = 0;

void DFS(int x, int y)
{
    if(m[x][y] != 1) return;
    else m[x][y] = answer;
    DFS(x-1, y-1);
    DFS(x-1, y);
    DFS(x-1, y+1);
    DFS(x, y-1);
    DFS(x, y+1);
    DFS(x+1, y-1);
    DFS(x+1, y);
    DFS(x+1, y+1);
}

int main()
{
    while(true)
    {
        int w, h;
        answer = 0;
        scanf("%d %d", &w, &h);
        if(w == 0 && h == 0) break;
        memset(m, 0, sizeof(m));
        for(int i = 1; i <= h; i++)
            for(int j = 1; j <= w; j++)
                scanf("%d", &m[i][j]);
        for(int i = 1; i <= h; i++)
            for(int j = 1; j <= w; j++)
                if(m[i][j] == 1) { answer--; DFS(i, j); }
        printf("%d\n", -answer);
    }

}
