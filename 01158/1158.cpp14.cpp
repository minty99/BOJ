#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	queue<int> Q;
	for(int i = 1; i <= n; i++) Q.push(i);
	printf("<");
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j < m; j++)
		{
			int k = Q.front();
			Q.pop();
			Q.push(k);
		}
		if(i != n) printf("%d, ", Q.front());
		else printf("%d>", Q.front());
		Q.pop();
	}
}
