#include <stdio.h>

int main()
{
    int curr = 0;
    int max = 0;
    for(int i = 1; i <= 4; i++)
    {
        int out, in;
        scanf("%d %d", &out, &in);
        curr -= out;
        curr += in;
        if(max < curr) max = curr;
    }
    printf("%d", max);
}