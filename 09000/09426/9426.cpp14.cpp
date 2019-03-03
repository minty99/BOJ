#include <cstdio>
#include <algorithm>

using namespace std;
int tree[131073];
int arr[250001];
int n, k, m;

int get()
{
    int key = (k+1)/2;
    int mid;
    int left = 1;
    int right = m;
    while(left < right)
    {
        mid = (left + right) / 2;
        if(tree[mid] >= key) right = mid;
        else
        {
            left = mid + 1;
            key -= tree[mid];
        }
    }
    return left;
}

void add(int i)
{
    while(i <= m)
    {
        tree[i]++;
        i += (i & -i);
    }
}

void sub(int i)
{
    while(i <= m)
    {
        tree[i]--;
        i += (i & -i);
    }
}

int main()
{
    int mmax=0;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        arr[i]++;
        if(mmax < arr[i]) mmax = arr[i];
    }
    for(m=1 ; m<mmax ; m<<=1);
    for(int i = 1; i <= k; i++) add(arr[i]);
    long long answer = get()-1;

    for(int i = k+1; i <= n; i++)
    {
        add(arr[i]);
        sub(arr[i-k]);
        answer += get()-1;
    }

    printf("%lld", answer);
}
