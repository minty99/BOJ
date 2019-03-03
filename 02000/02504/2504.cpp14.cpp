#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

void FC()
{
	printf("0");
	exit(0);
}

int calc(string s)
{
	if(s == "()") return 2;
	if(s == "[]") return 3;
	if(s.length() <= 2) FC();

	if(s.front() == '(')
	{
		int level = 0;
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] == '(') level++;
			if(s[i] == ')') level--;
			if(level == 0 && i == s.length()-1)
				return 2 * calc(s.substr(1, s.length() - 2));
			if(level == 0)
				return calc(s.substr(0, i+1)) + calc(s.substr(i+1, s.length() - (i+1)));
		}
		FC();
	}
	if(s.front() == '[')
	{
		int level = 0;
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] == '[') level++;
			if(s[i] == ']') level--;
			if(level == 0 && i == s.length()-1)
				return 3 * calc(s.substr(1, s.length() - 2));
			if(level == 0)
				return calc(s.substr(0, i+1)) + calc(s.substr(i+1, s.length() - (i+1)));
		}
		FC();
	}
	FC();
}

int main()
{
	string s;
	cin >> s;
	printf("%d\n", calc(s));
}
