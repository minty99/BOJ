#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	// freopen("in.txt", "r", stdin);

    int n;
    scanf("%d", &n);
	while(true)
	{
		if(n == 0) break;
		vector<int> v(n);
		for(int i = 0; i < n; i++) scanf("%d", &v[i]);

		for(int a = 0; a < n; a++)
			for(int b = a+1; b < n; b++)
				for(int c = b+1; c < n; c++)
					for(int d = c+1; d < n; d++)
						for(int e = d+1; e < n; e++)
							for(int f = e+1; f < n; f++)
								printf("%d %d %d %d %d %d\n", v[a], v[b], v[c], v[d], v[e], v[f]);
		scanf("%d", &n);
        if(n == 0) break;
        puts("");
	}
}
