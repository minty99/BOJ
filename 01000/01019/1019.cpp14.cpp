#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long lli;
lli answer[10];
int n;

int main()
{
	int n;
	scanf("%d", &n);

	if(n < 100000)
	{
		for(int i = 1; i <= n; i++)
		{
			string s = to_string(i);
			for(char t : s) answer[t-'0']++;
		}
	}
	else
	{
		int a = n / 100000;
		// 1~99999
		answer[0] = 38889;
		for(int i = 1; i < 10; i++) answer[i] = 50000;
		// 100000 ~ a*100000-1
		for(int i = 1; i < a; i++)
		{
			string s = to_string(i);
			if(i == 0) s = "";
			for(char t : s) answer[t-'0'] += 100000;
			for(int j = 0; j < 10; j++) answer[j] += 50000;
		}

		// a*100000 ~ n
		for(int i = a * 100000; i <= n; i++)
		{
			string s = to_string(i);
			for(char t : s) answer[t-'0']++;
		}
	}

	for(int k : answer) printf("%d ", k);
}
