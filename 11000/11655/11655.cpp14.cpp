#include <cstdio>
#include <cstring>
#include <cstdlib>
char s[200];
int main()
{
    fgets(s, 200, stdin);
    int l = strlen(s);
    for(int i = 0; i < l; i++)
    {
        int k = s[i];
        if('A' <= s[i] && s[i] <= 'Z')
        {
        	k += 13;
        	if(k > 'Z') k -= 26;
        }
        if('a' <= s[i] && s[i] <= 'z')
        {
        	k += 13;
        	if(k > 'z') k -= 26;
        }
        s[i] = k;
    }
    printf("%s", s);
}