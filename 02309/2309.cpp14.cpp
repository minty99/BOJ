#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int arr[10], total = 0;
	for(int i = 1; i <= 9; i++)
	{
		scanf("%d", &arr[i]);
		total += arr[i];
	}

	for(int i = 1; i <= 9; i++)
	{
		for(int j = 1; j <= 9; j++)
		{
			if(i == j) continue;
			if(total - arr[i] - arr[j] == 100)
			{
				arr[i] = 1000;
				arr[j] = 1000;
				sort(arr+1, arr+9+1);
				for(int k = 1; k <= 7; k++)
				{
					printf("%d\n", arr[k]);
				}
			}
		}
	}
}
