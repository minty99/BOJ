#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int main()
{
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		v.push_back(t);
	}

	sort(v.begin(), v.end());
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		int k;
		scanf("%d", &k);
		if(binary_search(v.begin(), v.end(), k)) puts("1");
		else puts("0");
	}
}
