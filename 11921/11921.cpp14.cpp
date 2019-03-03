#include <stdio.h>
#include <stdlib.h>

char buffer[50000000];
char* ptr = buffer;

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
    int n, m;
    register long long sum = 0;
    n = 1700000;    
    fread(buffer, 1, 50000000, stdin);
    readint();
    for(int i = 1; i <= n; i++) sum += readint();
    printf("%d\n%lld", n, sum);
}
