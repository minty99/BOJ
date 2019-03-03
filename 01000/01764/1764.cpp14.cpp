#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <random>
#include <array>
#define x first
#define y second
#define MOD 1000000007
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long int ulli;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    unordered_set<string> us;
    priority_queue<string, vector<string>, greater<string>> ans;

    for(int i = 0; i < n+m; i++)
    {
        string s;
        cin >> s;
        if(us.find(s) != us.end()) ans.push(s);
        else us.insert(s);
    }

    cout << ans.size() << '\n';
    int sz = ans.size();
    for(int i = 0; i < sz; i++)
    {
        cout << ans.top() << '\n';
        ans.pop();
    }
}
