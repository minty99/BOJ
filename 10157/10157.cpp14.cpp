#include <cstdio>

int seat[1001][1001];

int main()
{
	int c, r, k;
	scanf("%d %d %d", &c, &r, &k);
	if(c*r < k)
	{
		printf("0");
		return 0;
	}
	int x = 1, y = 1;
	int phase = 1;	// 1: up, 2: right, 3: down, 4: left
	int i = 1;
	int depth = 0;
	while(true)
	{
		if(phase == 1 && y == r-depth) phase = 2;
		if(phase == 2 && x == c-depth) phase = 3;
		if(phase == 3 && y == depth+1) phase = 4;
		if(phase == 4 && x == depth+2) { phase = 1; depth++; }
		seat[x][y] = i;
		if(i == k) break;
		if(phase == 1) y++;
		if(phase == 2) x++;
		if(phase == 3) y--;
		if(phase == 4) x--;
		i++;
	}
	printf("%d %d", x, y);
}
