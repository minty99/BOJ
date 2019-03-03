#include <stdio.h>
#include <vector>
using namespace std;

int min(int a, int b) { return a < b ? a : b; }
int calcD(int ar, int ag, int ab, int br, int bg, int bb)
{
    return (ar-br)*(ar-br)+(ag-bg)*(ag-bg)+(ab-bb)*(ab-bb);
}

int main()
{
    int k, n, r[201], g[201], b[201];
    scanf("%d", &k);
    for(int i = 1; i <= k; i++)
    {
        scanf("%d", &n);
        vector<int> ans;
        for(int j = 1; j <= n; j++) scanf("%d %d %d", &r[j], &g[j], &b[j]);
        int max_d = 0;
        for(int j = 1; j <= n; j++)
        {
            for(int m = j+1; m <= n; m++)
            {
                if(calcD(r[j], g[j], b[j], r[m], g[m], b[m]) > max_d)
                {
                    ans.clear();
                    ans.push_back(j);
                    ans.push_back(m);
                    max_d = calcD(r[j], g[j], b[j], r[m], g[m], b[m]);
                }
                else if(calcD(r[j], g[j], b[j], r[m], g[m], b[m]) == max_d)
                {
                    ans.push_back(j);
                    ans.push_back(m);
                }
            }
        }
        printf("Data Set %d:\n", i);
        for(int j = 0; j < ans.size(); j+=2) printf("%d %d\n", ans[j], ans[j+1]);
    }
}
