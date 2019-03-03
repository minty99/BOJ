#include <cstdio>

using namespace std;
int table[60][60];
int cnt[60];
int main()
{
	int n;
	scanf("%d", &n);

	char tmp[100];
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", tmp);
		for(int j = 0; j < n; j++)
		{
			if(tmp[j] == 'Y') table[i][j+1] = table[j+1][i] = 1;
		}
	}

	int M = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i == j) continue;
			if(table[i][j] == 1) cnt[i] += 1;
			else
			{
				for(int k = 1; k <= n; k++)
				{
					if(k == i || k == j) continue;
					if(table[i][k] == 1 && table[k][j] == 1)
					{
						cnt[i] += 1;
						break;
					}
				}
			}
		}
		if(cnt[i] > M) M = cnt[i];
	}

	printf("%d", M);
}
