#include <cstdio>
#include <stack>
#include <vector>

using namespace std;
stack<int> st;
vector<char> out;

int main()
{
	int n;
	scanf("%d", &n);
	int curr = 0;

	for(int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);
		if(!st.empty() && st.top() > k)
		{
			puts("NO");
			return 0;
		}
		while(st.empty() || st.top() != k)
		{
			out.push_back('+');
			st.push(++curr);
		}
		out.push_back('-');
		st.pop();
	}

	for(char c : out) printf("%c\n", c);
}
