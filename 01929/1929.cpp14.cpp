#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main()
{
	v.push_back(2);
	v.push_back(3);
	for(int i = 5; i <= 1000000; i += 2)
	{
		for(int j = 0; v[j]*v[j] < i; j++)
		{
			if(i % v[j] == 0) break;
			if(v[j+1] * v[j+1] > i) v.push_back(i);
		}
	}

	int a, b;
	scanf("%d %d", &a, &b);
	auto min_it = lower_bound(v.begin(), v.end(), a);
	auto max_it = upper_bound(v.begin(), v.end(), b);
	for(auto it = min_it; it != max_it; it++) printf("%d\n", *it);

}
