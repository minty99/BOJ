#include <cstdio>
#include <vector>
using namespace std;

int arr[200];
vector<int> bucket[200];
int main()
{
    // freopen("in.txt", "r", stdin);
    // setbuf(stdout, NULL);
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    for(int j = 1; j <= k; j++) bucket[j].push_back(0);

    for(int i = 1; i <= n; i++)
    {
        int m = -1;
        int togo = -1;
        for(int j = 1; j <= k; j++)
        {
            if(bucket[j].back() < arr[i] && bucket[j].back() > m)
            {
                togo = j;
                m = bucket[j].back();
            }
        }
        if(togo == -1) { printf("NO"); return 0; }
        bucket[togo].push_back(arr[i]);
    }
    printf("YES");
}