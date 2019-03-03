#include <cstdio>
#include <iostream>
#include <cassert>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <sstream>
#include <bitset>
#include <random>
#define x first
#define y second
#define MOD 1000000007
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long int ulli;

int main()
{
    int t;
    scanf("%d", &t);

	for(int z = 1; z <= t; z++)
	{
		int n;
		scanf("%d", &n);
		vector<lli> v;
		for(int i = 1; i <= 2*n; i++)
		{
			int a;
			scanf("%d", &a);
			v.push_back(a);
		}

		vector<lli> ans;
		for(int i = 1; i <= n; i++)
		{
			ans.push_back(v[0]);
			for(int j = 0; j < v.size(); j++)
			{
				if(v[j] == v[0] * 4 / 3) { v.erase(v.begin()+j); break; }
			}
			v.erase(v.begin());
		}

		printf("Case #%d: ", z);
		for(int i = 0; i < n; i++)
		{
			if(i != n-1) printf("%lld ", ans[i]);
			else printf("%lld\n", ans[i]);
		}
	}
}
