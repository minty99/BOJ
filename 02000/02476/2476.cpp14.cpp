#include <cstdio>
#include <algorithm>
#define max(a, b) ((a) > (b) ? (a) : (b))

int main()
{
	int n;
	scanf("%d", &n);

	int max_value = 0;
	for(int i = 1; i <= n; i++)
	{
		int award = 0;
		int arr[4];
		scanf("%d %d %d", &arr[1], &arr[2], &arr[3]);
		std::sort(arr+1, arr+4);
		if(arr[1] == arr[2] && arr[2] == arr[3]) award = 10000 + arr[3]*1000;
		else if(arr[2] == arr[3]) award = 1000 + arr[3] * 100;
		else award = arr[3] * 100;
		max_value = max(max_value, award);
	}
	printf("%d", max_value);
}
