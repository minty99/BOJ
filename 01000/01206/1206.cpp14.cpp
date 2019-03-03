#include <cstdio>
#include <cmath>
#include <algorithm>
#define min(a, b) ((a) < (b) ? (a) : (b))

using namespace std;
int k[101];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int a, b;
		scanf("%d.%d", &a, &b);
		k[i] = a * 1000 + b;
	}

	sort(k+1, k+n+1);
	int ptr = 1;
	for(int i = 1; i <= 1000; i++)
	{
		ptr = 1;
		for(int j = 0; j <= i * 10; j++)
		{
			if(ptr == n+1) break;
			int err = j*1000/i - k[ptr];
			if(err == 0) { ptr++; j--; }
		}
		if(ptr == n+1)
		{
			printf("%d", i);
			return 0;
		}
	}
}
