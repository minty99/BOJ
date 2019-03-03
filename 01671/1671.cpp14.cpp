#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

typedef struct shark {
	int a, b, c;
} Shark;

Shark s[1100];
int c[2200][2200];
int f[2200][2200];
vector<int> adj[1100];
int n;
stack<int> st, way;

inline bool canEat(int i, int j)
{
	Shark a = s[i];
	Shark b = s[j];
	if(a.a == b.a && a.b == b.b && a.c == b.c) return (i < j);
	return ((a.a >= b.a) && (a.b >= b.b) && (a.c >= b.c));
}

bool MaximumFlow()
{
	int prev[3000];
	fill(prev, prev+3000, -1);
	prev[0] = 0;
	queue<int> Q;
	Q.push(0);

    while(!Q.empty())
    {
        int num = Q.front();
        Q.pop();
		if(num == 2*n+1)
		{
			int mini = 2e9;
			int curr = 2*n+1;
			while(true)
			{
				way.push(curr);
				st.push(curr);
				if(curr == 0) break;
				curr = prev[curr];
			}

			int a;
			int b = st.top();
			st.pop();
	        while(!st.empty())
	        {
				a = b;
				b = st.top();
				st.pop();
	            int r = c[a][b] - f[a][b];
	            if(mini > r) mini = r;
	        }

			b = way.top();
			way.pop();
	        while(!way.empty())
	        {
				a = b;
				b = way.top();
				way.pop();
	            f[a][b] += mini;
	            f[b][a] -= mini;
			}
	        return true;
		}
        for(int next : adj[num])
        {
            if(f[num][next] < c[num][next] && prev[next] == -1)
			{
				Q.push(next);
				prev[next] = num;
			}
        }
    }
	return false;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		adj[0].push_back(i);
		adj[i].push_back(0);
		c[0][i] = 2;

		adj[n+i].push_back(2*n+1);
		adj[2*n+1].push_back(n+i);
		c[n+i][2*n+1] = 1;
	}

	for(int i = 1; i <= n; i++)
		scanf("%d %d %d", &s[i].a, &s[i].b, &s[i].c);

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i == j) continue;
			if(canEat(i, j)) {
				c[i][n+j] = 1;
				adj[i].push_back(n+j);
				adj[n+j].push_back(i);
			}
		}
	}

    while (MaximumFlow());
    int MF = 0;
    for(int i = 0; i < adj[0].size(); i++)
        MF += f[0][adj[0][i]];
    printf("%d", n - MF);
}
