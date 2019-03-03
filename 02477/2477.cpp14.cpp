#include <stdio.h>

int main()
{
	int k;
	scanf("%d", &k);
	int dir[13], len[13];
	for(int i = 1; i <= 6; i++)
	{
		scanf("%d %d", &dir[i], &len[i]);
		dir[i+6] = dir[i];
		len[i+6] = len[i];
	}

	int horizontal = 0, vertical = 0;
	for(int i = 1; i <= 6; i++)
	{
		if(dir[i] == 1) horizontal += len[i];
		if(dir[i] == 3) vertical += len[i];
	}

	int S = horizontal * vertical;
	int small_S;
	for(int i = 1; i <= 9; i++)
		if(dir[i] == dir[i+2] && dir[i+1] == dir[i+3]) small_S = len[i+1] * len[i+2];
	printf("%d", k * (S - small_S));
}
