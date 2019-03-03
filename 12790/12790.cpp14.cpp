#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++)
	{
		int hp, mp, agg, def;
		int a, b, c, d;
		scanf("%d %d %d %d", &hp, &mp, &agg, &def);
		scanf("%d %d %d %d", &a, &b, &c, &d);
		hp += a;
		mp += b;
		agg += c;
		def += d;
		if(hp < 1) hp = 1;
		if(mp < 1) mp = 1;
		if(agg < 0) agg = 0;

		printf("%d\n", hp + 5*mp + 2*agg + 2*def);
	}
}
