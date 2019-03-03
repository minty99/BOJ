#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;

deque<int> dq;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) dq.push_back(i);

	int answer = 0;
	for(int i = 1; i <= m; i++)
	{
		int k;
		scanf("%d", &k);
		auto it = find(dq.begin(), dq.end(), k);
		int idx = it - dq.begin();
		if(idx > dq.size()/2)	// right
		{
			while(dq.front() != k)
			{
				int t = dq.back();
				dq.push_front(t);
				dq.pop_back();
				answer++;
			}
			dq.pop_front();
		}
		else // left
		{
			while(dq.front() != k)
			{
				int t = dq.front();
				dq.push_back(t);
				dq.pop_front();
				answer++;
			}
			dq.pop_front();
		}
	}

	printf("%d", answer);
}
