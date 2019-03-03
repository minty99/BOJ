#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int main()
{
	int t;
	scanf("%d", &t);
	while(t --> 0)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		queue<pii> Q;
		priority_queue<int> pQ;
		for(int i = 0; i < n; i++)
		{
			int k;
			scanf("%d", &k);
			Q.emplace(i, k);
			pQ.push(k);
		}

		int cnt = 0;
		while(!Q.empty())
		{
			while(Q.front().second != pQ.top())
			{
				pii p = Q.front();
				Q.pop();
				Q.push(p);
			}

			if(Q.front().first == m)
			{
				cnt++;
				printf("%d\n", cnt);
				break;
			}
			else
			{
				cnt++;
				Q.pop();
				pQ.pop();
			}
		}
	}
}
