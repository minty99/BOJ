#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	char s[20];
	scanf("%s", s);
	sort(s, s+strlen(s), [](char a, char b) { return a>b; } );
	printf("%s", s);
}
