#include <stdio.h>

char buffer[10000000];
char* ptr = buffer;
int a, b;

inline int readint()
{
    int n = 0;
    while(true)
    {
        if(*ptr < '0' || *ptr > '9') break;
        n = (n << 1) + (n << 3) + (*ptr-'0');
        ptr++;
    }
    ptr++;
    return n;
}

int main()
{
	int t;
	fread(buffer, 1, 10000000, stdin);
	t = readint();
	for(int i = 1; i <= t; i++)
	{
		a = readint();
		b = readint();
		printf("%d\n", a+b);
	}
}
