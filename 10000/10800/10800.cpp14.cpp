#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class Ball {
public:
	int number, color, size;
	Ball(int n, int c, int s) {
		number = n;
		color = c;
		size = s;
	}

};

bool compare(const Ball &a, const Ball &b)
{
	return a.size < b.size;
}

vector<Ball> balls;
int sum[200001];
int answer[200001];
int total = 0;

int main()
{
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
	{
		int c, s;
		scanf("%d %d", &c, &s);
		balls.push_back(Ball(i, c, s));
	}

	sort(balls.begin(), balls.end(), compare);

	int idx = 0;
	while(idx < balls.size())
	{
		int i = idx;
		do
		{
			answer[balls[i].number] = total - sum[balls[i].color];
			i++;
		} while(balls[i-1].size == balls[i].size && i < balls.size());

		for(int k = idx; k < i; k++)
		{
			total += balls[k].size;
			sum[balls[k].color] += balls[k].size;
		}
		idx = i;
	}
	for(int i = 1; i <= n; i++)
	{
		printf("%d\n", answer[i]);
	}

}
