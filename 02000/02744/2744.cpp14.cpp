#include <cstdio>
#include <cstring>

int main()
{
    char s[200];
    scanf("%s", s);
    
    for(int i = 0; i < strlen(s); i++)
    {
        if('A' <= s[i] && s[i] <= 'Z') s[i] += 32;
        else s[i] -= 32;
    }
    printf("%s", s);
}