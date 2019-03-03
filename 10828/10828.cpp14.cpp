#include <cstdio>
#include <stack>    // C++ stack (스택의 개념과 C++ STL stack의 사용법을 배운 후에 풀어야 하는 문제입니다.)
#include <string>   // C++ string
using namespace std;

stack<int> st;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        string cmd;
        char s[10];
        scanf("%s", s);
        cmd = string(s);
        if(cmd == "push")
        {
            int k;
            scanf("%d", &k);
            st.push(k);
        }
        if(cmd == "top")
        {
            if(st.size() == 0) printf("-1\n");
            else printf("%d\n", st.top());
        }
        if(cmd == "size") printf("%d\n", (int)st.size());
        if(cmd == "empty") printf("%d\n", st.empty());
        if(cmd == "pop")
        {
            if(st.size() == 0) printf("-1\n");
            else
            {
                printf("%d\n", st.top());
                st.pop();
            }
        }
    }
}
