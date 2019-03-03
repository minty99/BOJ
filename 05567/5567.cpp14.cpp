#include <cstdio>
#include <vector>
#include <set>
using namespace std;

set<int> v[501];
set<int> s;

void DFS()
{
	for(auto i = v[1].begin(); i != v[1].end(); i++)
	{
		s.insert(*i);
		for(auto j = v[*i].begin(); j != v[*i].end(); j++)
			s.insert(*j);
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 1; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].insert(b);
		v[b].insert(a);
	}

	DFS();
	s.erase(1);
	printf("%lu", s.size());
}
