#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) v.push_back(i+1);
    
    do
    {
        for(int i = 0; i < n; i++) printf("%d ", v[i]);
        puts("");
    } while(next_permutation(v.begin(), v.end()));
}