#include <cstdio>
#include <cstring>
using namespace std;

int arr[110];

int solve(int n)
{
	memset(arr, 0, sizeof(arr));
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j += i)
		{
			if(arr[j] == 0) arr[j] = 1;
			else arr[j] = 0;
		}
	}

	int ret = 0;
	for(int i = 1; i <= n; i++) ret += arr[i];
	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);

	while(t --> 0)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", solve(n));
	}
}
