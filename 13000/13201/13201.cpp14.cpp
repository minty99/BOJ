#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

typedef pair<int, int> pii;
typedef long long lli;

double table[101][101];
double result[101];
int main()
{
    // freopen("in.txt", "r", stdin);
    int t, n, k;
    string s[101];

    scanf("%d", &t);
    while(t > 0)
    {
        t--;

        for(int i = 1; i <= 100; i++)
        {
            for(int j = 1; j <= 100; j++) table[i][j] = 0;
            result[i] = -INFINITY;
        }
        scanf("%d %d", &n, &k);
        int start = 0;
        for(int i = 1; i <= n; i++) { cin >> s[i]; if(s[i] == "ICN") start = i; }
        for(int i = 1; i <= n; i++)
        {
            int sum = 0;
            for(int j = 1; j <= n; j++)
            {
                int tmp;
                scanf("%d", &tmp);
                table[i][j] = (double)tmp;
                sum += tmp;
            }
            for(int j = 1; j <= n; j++) table[i][j] = log(table[i][j]) - log(sum);
        }

        result[start] = 0;
        for(int i = 1; i <= k; i++)
        {
            double new_result[101];
            for(int j = 1; j <= n; j++)
            {
                double maxi = -INFINITY;
                for(int m = 1; m <= n; m++)
                    if(maxi < table[m][j] + result[m]) maxi = table[m][j] + result[m];
                new_result[j] = maxi;
            }
            for(int j = 1; j <= n; j++) result[j] = new_result[j];
        }
        double M = -INFINITY;
        int answer = 0;
        for(int i = 1; i <= n; i++)
        {
            if(M < result[i])
            {
                M = result[i];
                answer = i;
            }
        }

        cout << s[answer] << endl;
    }
}