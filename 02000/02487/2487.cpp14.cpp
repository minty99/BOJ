#include <cstdio>

int v[20001];
int cycle_count[20001];

int GCD(int a, int b)
{
	if(b == 0) return a;
	return GCD(b, a%b);
}

int LCM(int a, int b)
{
	return a/GCD(a, b)*b;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &v[i]);
	}

	for(int i = 1; i <= n; i++) cycle_count[i] = 1;
	for(int i = 1; i <= n; i++)
	{
		int curr = v[i];
		while(true)
		{
			if(curr == i) break;
			if(cycle_count[curr] != 1)
			{
				cycle_count[i] = cycle_count[curr];
				break;
			}
			curr = v[curr];
			cycle_count[i]++;
		}
	}
	int L = 1;
	for(int i = 1; i <= n; i++) L = LCM(L, cycle_count[i]);
	printf("%d", L);
}
