#include <cstdio>
using namespace std;

int main()
{
    int arr[1000];
    int c;
    scanf("%d", &c);
    for(int z = 1; z <= c; z++)
    {
        int n;
        scanf("%d", &n);
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        double avg = (double) sum / n;
        
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] > avg) cnt++;
        }
        printf("%.3f%%\n", (double)cnt / n * 100);
    }
}