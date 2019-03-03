#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T --> 0)
    {
        int n;
        scanf("%d", &n);
        int r[1000];
        memset(r, 0, sizeof(r));
        for(int i = 1; i <= n; i++)
        {
            int t;
            scanf("%d", &t);
            r[t] = i;
        }
        int m;
        scanf("%d", &m);
        int matrix[1000][1000];
        int size[1000];
        memset(matrix, 0, sizeof(matrix));
        memset(size, 0, sizeof(size));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(r[i] < r[j])
                {
                    matrix[i][j] = 1;
                    size[i]++;
                }
            }
        }

        for(int i = 1; i <= m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            // a->b: a가 더 랭킹이 높다.
            if(r[a] < r[b])
            {
                matrix[a][b] = 0;
                matrix[b][a] = 1;
                size[a]--;
                size[b]++;
            }
            if(r[a] > r[b])
            {
                matrix[a][b] = 1;
                matrix[b][a] = 0;
                size[a]++;
                size[b]--;
            }
        }

        vector<int> topo;
        int next = -1;
        bool fail = false;
        for(int i = 1; i <= n; i++)
        {
            if(size[i] == 0 && next == -1) next = i;
            else if(size[i] == 0 && next != 0)
            {
                printf("?\n");
                fail = true;
                break;
            }
        }
        if(fail) continue;
        if(next == -1)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }

        fail = false;
        for(int i = 1; i <= n; i++)
        {
            if(next == -1)
            {
                printf("IMPOSSIBLE\n");
                fail = true;
                break;
            }
            int j = next;
            next = -1;
            if(size[j] == 0)
            {
                size[j] = -1;
                for(int k = 1; k <= n; k++)
                {
                    if(matrix[k][j] == 1)
                    {
                        matrix[k][j] = 0;
                        size[k]--;
                        if(size[k] == 0 && next == -1) next = k;
                        else if(size[k] == 0 && next != -1)
                        {
                            printf("?\n");
                            continue;
                        }
                    }
                }
                topo.push_back(j);
            }
        }
        if(fail) continue;

        for(int i = topo.size()-1; i >= 0; i--) printf("%d ", topo[i]);
        puts("");
    }
}
