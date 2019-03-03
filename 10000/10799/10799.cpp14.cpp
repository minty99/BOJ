#include <cstdio>
#include <string>

using namespace std;

int main()
{
	char t[100001];
	scanf("%s", t);
	string s(t);

	int level = 0, answer = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '(' && s[i+1] == ')') answer += level;
		else if(s[i] == ')' && s[i-1] == '(') continue;
		else if(s[i] == '(')
		{
			answer++;
			level++;
		}
		else if(s[i] == ')') level--;
	}
	printf("%d", answer);
}
