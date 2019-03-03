#include <cstdio>

int arr[21];

void swp(int a, int b)
{
	int t = arr[a];
	arr[a] = arr[b];
	arr[b] = t;
}

void rev(int left, int right)
{
	while(left < right)
	{
		swp(left, right);
		left++;
		right--;
	}
}

int main()
{
	for(int i = 1; i <= 20; i++) arr[i] = i;

	for(int i = 1; i <= 10; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		rev(a, b);
	}

	for(int i = 1; i <= 20; i++) printf("%d ", arr[i]);
}
