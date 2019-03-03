#include <cstdio>
#include <list>
#include <algorithm>
#include <utility>
using namespace std;

list<int> v;
int n, m, l;

int find_answer(int left, int right)
{
	int mid = (left + right) / 2;
	if(mid == 0) return find_answer(1, 1);
	list<int> vv(v);
	int cnt = 0;
	for(auto it = vv.begin(); ; it++)
	{
		auto second = next(it);
		if(second == vv.end()) break;
		if(*second - *it > mid)
		{
			vv.insert(second, *it + mid);
			cnt++;
		}
	}
    
	if(cnt <= m && left == right) return left;
	if(cnt <= m) return find_answer(left, mid);
	else return find_answer(mid+1, right);
}

int main()
{
	scanf("%d %d %d", &n, &m, &l);
	for(int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);
		v.push_back(k);
	}
	v.push_back(0);
	v.push_back(l);
	v.sort();

	int ans = find_answer(0, l);
	printf("%d", ans);
}
