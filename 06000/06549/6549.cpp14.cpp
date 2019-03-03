#include <cstdio>
#include <vector>

typedef long long lli;
lli calc(int start, int end);
lli calc_mid(int start, int end);
std::vector<int> heights;

inline lli max(lli a, lli b)
{
	return (a>b) ? a : b;
}

inline lli min(lli a, lli b)
{
	return (a<b) ? a : b;
}

inline lli max(lli a, lli b, lli c)
{
	return max(max(a, b), c);
}

int main()
{
	int n;
	while(true)
	{
		scanf("%d", &n);
		if(n == 0) break;
		for(int i = 1; i <= n; i++)
		{
			int s;
			scanf("%d", &s);
			heights.push_back(s);
		}

		printf("%lld\n", calc(0, n-1));
		heights.clear();
	}
}

lli calc(int start, int end)
{
	if(start == end) return heights[start];
	int mid = (start+end)/2;
	lli ret = max(calc(start, mid), calc_mid(start, end), calc(mid+1, end));
	return ret;
}

lli calc_mid(int start, int end)
{
	int mid = (start+end)/2;
	int left = mid;
	int right = mid+1;
	lli current_height = min(heights[left], heights[right]);
	lli current_max = 2 * current_height;
	while(true)
	{
		if(left != start and right != end)
		{
			if(heights[left-1] > heights[right+1])
				current_height = min(current_height, heights[--left]);
			else
				current_height = min(current_height, heights[++right]);
		}
		else if(left != start)
		{
			current_height = min(current_height, heights[--left]);
		}
		else if(right != end)
		{
			current_height = min(current_height, heights[++right]);
		}
		else
		{
			current_max = max(current_max, current_height * (right - left + 1));
			break;
		}
		current_max = max(current_max, current_height * (right - left + 1));
	}
	return current_max;
}
