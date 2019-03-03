#include <cstdio>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int dp_inc[1100], dp_dec[1100], arr[1100];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			if(dp_inc[j] >= dp_inc[i] && arr[j] < arr[i]) dp_inc[i] = dp_inc[j] + 1;
			if(dp_dec[j] >= dp_dec[i] && arr[j] > arr[i]) dp_dec[i] = dp_dec[j] + 1;
			if(dp_inc[j] >= dp_dec[i] && arr[j] > arr[i]) dp_dec[i] = dp_inc[j] + 1;
		}
	}

	int answer = 0;
	for(int i = 1; i <= n; i++) answer = max(max(dp_inc[i], dp_dec[i]), answer);
	printf("%d", answer);
}
