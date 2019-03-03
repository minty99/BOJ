#include <cstdio>
#include <deque>
#include <string>
using namespace std;

deque<int> dq;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        string cmd;
        char s[20];
        scanf("%s", s);
        cmd = string(s);
        if(cmd == "push_front")
        {
            int k;
            scanf("%d", &k);
            dq.push_front(k);
        }
		if(cmd == "push_back")
        {
            int k;
            scanf("%d", &k);
            dq.push_back(k);
        }
        if(cmd == "front")
        {
            if(dq.size() == 0) printf("-1\n");
            else printf("%d\n", dq.front());
        }
		if(cmd == "back")
        {
            if(dq.size() == 0) printf("-1\n");
            else printf("%d\n", dq.back());
        }
        if(cmd == "size") printf("%d\n", (int)dq.size());
        if(cmd == "empty") printf("%d\n", dq.empty());
        if(cmd == "pop_front")
        {
            if(dq.size() == 0) printf("-1\n");
            else
            {
                printf("%d\n", dq.front());
                dq.pop_front();
            }
        }
		if(cmd == "pop_back")
        {
            if(dq.size() == 0) printf("-1\n");
            else
            {
                printf("%d\n", dq.back());
                dq.pop_back();
            }
        }
    }
}
