#include <cstdio>

typedef long long lli;

int main()
{
	lli s;
	scanf("%lld", &s);
	lli n = 1;
	while(n*(n+1)/2 <= s) n++;
	printf("%lld", n-1);
}
