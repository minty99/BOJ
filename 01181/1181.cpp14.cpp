#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

auto cmp = [](string a, string b) {
	if(a.length() != b.length()) return a.length() < b.length();
	else return a < b;
};

set<string, decltype(cmp)> v(cmp);

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		char s[100];
		scanf("%s", s);
		v.insert(s);
	}

	for(auto it = v.begin(); it != v.end(); it++) printf("%s\n", it->c_str());
}
