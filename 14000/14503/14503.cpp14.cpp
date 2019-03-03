#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int v[60][60];
int n, m;
int x, y, d;

inline void rotateLeft()
{
    d--;
    if(d < 0) d = 3;
}

inline void rotateRight()
{
    d++;
    if(d > 3) d = 0;
}

inline bool goForward()
{
    int xx = x, yy = y;
    if(d == 0) x--;
    if(d == 1) y++;
    if(d == 2) x++;
    if(d == 3) y--;
    if(v[x][y] == 1) { x = xx; y = yy; return false; }
    return true;
}

inline bool goBackward()
{
    int xx = x, yy = y;
    if(d == 0) x++;
    if(d == 1) y--;
    if(d == 2) x--;
    if(d == 3) y++;
    if(v[x][y] == 1) { x = xx; y = yy; return false; }
    return true;
}

inline bool checkAll()
{
    if(x-1 >= 0 && v[x-1][y] == 0) return true;
    if(y-1 >= 0 && v[x][y-1] == 0) return true;
    if(x+1 < n && v[x+1][y] == 0) return true;
    if(y+1 < m && v[x][y+1] == 0) return true;
    return false;
}

int main()
{
    // freopen("in.txt", "r", stdin);

    scanf("%d %d %d %d %d", &n, &m, &x, &y, &d);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &v[i][j]);

    int clean = 0;
    while(true)
    {
        if(v[x][y] == 0) clean++;
        v[x][y] = -1;
        // rule 3
        if(!checkAll())
        {
            bool ret = goBackward();
            // rule 4
            if(!ret) break;
            continue;
        }

        rotateLeft();
        bool ret = goForward();
        // rule 1, 2
        if(!ret) continue;
        if(v[x][y] != 0) { goBackward(); continue; }
        if(v[x][y] == 0) continue;
    }

    printf("%d", clean);
}
