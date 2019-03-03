#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

bool compare1(pair<int, int> p1, pair<int, int> p2)
{
    if(p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
}

bool compare2(pair<int, int> p1, pair<int, int> p2)
{
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int> > v;
    for(int i = 1; i <= n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end(), compare2);

    int now_time = v[0].second;
    int answer = 1;
    vector<pair<int, int> >::iterator p = v.begin();
    while(true)
    {
        p++;
        if(p >= v.end()) break;
        if((*p).first < now_time) continue;
        answer++;
        now_time = (*p).second;
    }
    printf("%d", answer);
}
