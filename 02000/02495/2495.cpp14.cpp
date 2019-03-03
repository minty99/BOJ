#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);

    for(int i = 1; i <= 3; i++)
    {
        char s[10];
        scanf("%s", s);

        int ans = 1;
        int curr = 1;
        for(int j = 1; j < 8; j++)
        {
            if(s[j] == s[j-1]) curr++;
            else
            {
                ans = max(ans, curr);
                curr = 1;
            }
        }
        ans = max(ans, curr);
        printf("%d\n", ans);
    }
}
