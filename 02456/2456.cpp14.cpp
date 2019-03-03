#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Student {
public:
	int number;
	int total;
	int vote[4];
};

int compare(const Student &a, const Student &b)
{
	if(a.total == b.total)
	{
		if(a.vote[3] == b.vote[3])
		{
			if(a.vote[2] == b.vote[2]) return 0;
			else return a.vote[2] > b.vote[2] ? 1 : 0;
		}
		else return a.vote[3] > b.vote[3] ? 1 : 0;
	}
	else return a.total > b.total ? 1 : 0;
}

int max(const Student &a, const Student &b)
{
	int ret = compare(a, b);
	if(ret >= 0) return a.total;
	else return b.total;
}

Student s[4];
int main()
{
	int n;
	scanf("%d", &n);
	s[1].number = 1;
	s[2].number = 2;
	s[3].number = 3;

	for(int i = 1; i <= n; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		s[1].total += a;
		s[1].vote[a]++;
		s[2].total += b;
		s[2].vote[b]++;
		s[3].total += c;
		s[3].vote[c]++;
	}

	sort(s+1, s+4, compare);
	if(s[1].total == s[2].total && s[1].vote[3] == s[2].vote[3] && s[1].vote[2] == s[2].vote[2])
		printf("0 %d", s[1].total);
	else printf("%d %d", s[1].number, s[1].total);
}
