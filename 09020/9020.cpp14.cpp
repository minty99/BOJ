#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main()
{
	v.push_back(2);
	v.push_back(3);
	for(int i = 5; i <= 10000; i += 2)
	{
		for(int j = 0; v[j]*v[j] < i; j++)
		{
			if(i % v[j] == 0) break;
			if(v[j+1] * v[j+1] > i) v.push_back(i);
		}
	}

	int t;
	scanf("%d", &t);
	while(t --> 0)
	{
		int n;
		scanf("%d", &n);
		auto min_it = lower_bound(v.begin(), v.end(), (n+1)/2);
		if(*min_it != n/2) min_it--;
		while(!binary_search(v.begin(), v.end(), n - (*min_it))) min_it--;
		printf("%d %d\n", *min_it, n - *min_it);
	}
}
