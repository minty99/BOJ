#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    scanf("%s", s);
    int height = 10;
    for(int i = 1; i < strlen(s); i++)
    {
        if(s[i] == s[i-1]) height += 5;
        else height += 10;
    }
    printf("%d", height);
}