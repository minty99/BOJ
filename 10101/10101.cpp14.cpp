#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
        int a[3];
        scanf("%d %d %d", &a[0], &a[1], &a[2]);

        sort(a, a+3);

        if(a[0] + a[1] + a[2] != 180) printf("Error");
        else if(a[0] == a[1] && a[1] == a[2]) printf("Equilateral");
        else if(a[0] == a[1] || a[1] == a[2]) printf("Isosceles");
        else printf("Scalene");
}