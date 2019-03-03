#include <stdio.h>

int main()
{
    int count = 0;
    for(int i = 0; i < 8; i++)
    {
        char s[10];
        scanf("%s", s);
        for(int j = i%2; j <= 8; j += 2)
        {
            if(s[j] == 'F') count++;
        }
    }
    printf("%d\n", count);
}
