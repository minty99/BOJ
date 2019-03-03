#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

char s[1200000];
int p = 0;
int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%s", s);

    int l = strlen(s);
    for(int i = 0; i < l; i++)
    {
        if(s[i] == 'P') p++;
        else if(s[i] == 'A')
        {
            if(p >= 2 && s[i+1] == 'P')
            {
                p -= 2;
            }
            else
            {
                printf("NP\n");
                return 0;
            }
        }
    }
    if(p == 1) printf("PPAP");
    else printf("NP");
}
