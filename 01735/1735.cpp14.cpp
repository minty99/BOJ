#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <bitset>
using namespace std;

int GCD(int a, int b)
{
    if(b == 0) return a;
    return GCD(b, a%b);
}

int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    int G = GCD(b, d);
    int L = b/G*d;

    a *= L/b;
    c *= L/d;
    
    G = GCD(a+c, L);
    printf("%d %d", (a+c)/G, L/G);
}
