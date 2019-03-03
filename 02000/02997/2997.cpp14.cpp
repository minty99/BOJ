#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	for(int i = 0; i < 3; i++)
	{
		int t;
		scanf("%d", &t);
		v.push_back(t);
	}
	sort(v.begin(), v.end());

	if(v[1] - v[0] == v[2] - v[1]) printf("%d", v[2] + (v[2] - v[1]));
	else if(v[1] - v[0] < v[2] - v[1]) printf("%d", v[1] + (v[1] - v[0]));
	else printf("%d", v[0] + v[2] - v[1]);
}
