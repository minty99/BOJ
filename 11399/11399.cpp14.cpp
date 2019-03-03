#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> data;

    for(int i = 1; i <= n; i++)
    {
        pair<int, int> p;
        p.first = i;
        scanf("%d", &p.second);
        data.push_back(p);
    }

    sort(data.begin(), data.end(), compare);
    int sum = 0, answer = 0;
    for(int i = 0; i < data.size(); i++)
    {
        sum += data[i].second;
        answer += sum;
    }

    printf("%d", answer);
}
