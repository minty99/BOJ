#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int v[501][2501];
int result[2501][2501];
int main()
{
	int b, c, t = 0;
	while(true)
	{
		start:
		memset(v, 0, sizeof(v));
		memset(result, 0, sizeof(result));
		t++;
		scanf("%d %d", &b, &c);
		if(b == 0 && c == 0) break;
		for(int i = 1; i <= b; i++)
		{
			for(int j = 1; j <= c; j++)
			{
				int k;
				scanf("%d", &k);
				v[i][k] = j;	// v[a][b] : a번째 리스트의 b번 후보의 등수
			}
		}

		for(int i = 0; i < c; i++)
		{
			bool con_win = true;
			for(int j = 0; j < c; j++)
			{
				if(i == j) continue;
				if(result[i][j] != 0)
				{
					if(result[i][j] == -1) { con_win = false; break; }
					if(result[i][j] == 1) continue;
				}
				int win = 0;
				int lost = 0;
				for(int k = 1; k <= b; k++)
				{
					if(v[k][i] < v[k][j]) win++;
					else lost++;
				}
				if(win > lost)
				{
					result[i][j] = 1;
					result[j][i] = -1;
				}
				if(win <= lost)
				{
					result[i][j] = -1;
					result[j][i] = 1;
					con_win = false;
					break;
				}
			}
			if(con_win)
			{
				printf("Case %d: %d\n", t, i);
				goto start;
			}
		}
		printf("Case %d: No Condorcet winner\n", t);
	}
}
