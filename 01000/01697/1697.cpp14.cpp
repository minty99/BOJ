#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <utility>

int n, k;
using namespace std;
queue<pair<int, int>> Queue;
bool memo[100001];

void process()
{
    while(true)
    {
        pair<int, int> p = Queue.front();
        Queue.pop();
        int n = p.first;
        int time = p.second;
        memo[n] = true;
        if(n == k)
        {
            printf("%d", time);
            exit(0);
        }

        if(n*2 <= 100000 && memo[n*2] == false) Queue.push(make_pair(n*2, time+1));
        if(n+1 <= 100000 && memo[n+1] == false) Queue.push(make_pair(n+1, time+1));
        if(n-1 >= 0 && memo[n-1] == false) Queue.push(make_pair(n-1, time+1));
    }
}
int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    scanf("%d %d", &n, &k);

    Queue.push(make_pair(n, 0));
    process();
}
