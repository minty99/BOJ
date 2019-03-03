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

bool isPrime[1000001];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 3; i <= 1000000; i += 2)
        isPrime[i] = true;
    for (int i = 3; i <= sqrt(1000000); i += 2)
    {
        if (!isPrime[i])
            continue;
        for (int j = i * 3; j <= 1000000; j += i * 2)
            isPrime[j] = false;
    }

    vector<int> primes;
    for (int i = 3; i <= 1000000; i += 2)
        if (isPrime[i])
            primes.push_back(i);

    int n;
    scanf("%d", &n);
    do
    {
        for (int i = 0; i < primes.size(); i++)
        {
            if (isPrime[n - primes[i]])
            {
                printf("%d = %d + %d\n", n, primes[i], n - primes[i]);
                break;
            }
        }
        scanf("%d", &n);
    } while (n != 0);
}