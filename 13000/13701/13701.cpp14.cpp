#include <stdio.h>

char arr[4200000];

int bit[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };

int main()
{
	int n, a, b;
	while(scanf("%d", &n) != EOF)
	{
        a = n/8;
        b = n%8;
		if(!(arr[a] & bit[b])) printf("%d ", n);
		arr[a] |= bit[b];
	}
}
