#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

vector<int> v;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    if(v.front() >= 0) printf("%d %d %d", v[0], v[1], v[2]);
    else if(v.back() <= 0) printf("%d %d %d", v[n-3], v[n-2], v[n-1]);
    else
    {
        int res_x, res_y, res_z, result = 2e9;
        for(int i = 0; i < n; i++)
        {
            int base = v[i];
            int left = i+1, right = n-1;
            int ans_x, ans_y, ans_abs = 2e9;
            while(left < right)
            {
                if(abs(base + v[left] + v[right]) < ans_abs) { ans_x = v[left]; ans_y = v[right]; ans_abs = abs(base + v[left] + v[right]); }
                if(abs(base + v[left] + v[right-1]) < abs(base + v[left] + v[right])) right--;
                else left++;
            }
            if(ans_abs < result)
            {
                res_x = base;
                res_y = ans_x;
                res_z = ans_y;
                result = ans_abs;
            }
        }

        printf("%d %d %d", res_x, res_y, res_z);
    }

}
