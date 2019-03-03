#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int v[110000];
char p[110000];
char in[500000];

int main()
{
	int t;
	scanf("%d", &t);
	while(t-- > 0)
	{
		int n;
		scanf("%s", p);
		scanf("%d", &n);
        scanf("%s", in);
        int len = strlen(in);
        int t = 0;
        int ptr = 0;
        for(int i = 1; i < len; i++)
		{
            if(in[i] == ',' || in[i] == ']') { v[ptr++] = t; t = 0; continue; }
            t = t * 10 + (in[i] - '0');
		}
		int start = 0;
		int end = n-1;
		bool reversed = false;
        int l = strlen(p);
        bool go = true;
		for(int i = 0; i < l; i++)
		{
			if(p[i] == 'R') reversed = !reversed;
			if(p[i] == 'D')
			{
				if(!reversed) start++;
				else end--;
			}

			if(end - start + 1 < 0) { printf("error\n"); go = false; break; }
		}
        if(!go) continue;
		if(end - start + 1 == 0) { printf("[]\n"); continue; }
		if(!reversed)
		{
			printf("[%d", v[start]);
			for(int i = start+1; i <= end; i++) printf(",%d", v[i]);
			printf("]\n");
		}
		else
		{
			printf("[%d", v[end]);
			for(int i = end-1; i >= start; i--) printf(",%d", v[i]);
			printf("]\n");
		}
	}
}
