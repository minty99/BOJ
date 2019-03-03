#include <cstdio>
#include <cstring>
using namespace std;

char s[200];
char cnt[27];
int main()
{
    scanf("%s", s);
    for(int i = 0; i < strlen(s); i++) cnt[s[i] - 'a']++;
    for(int i = 'a'; i <= 'z'; i++) printf("%d ", cnt[i - 'a']);
}