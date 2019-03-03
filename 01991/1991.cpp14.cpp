#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int, int> pii;

vector<pii> v(27, {0, 0});
vector<int> p1, p2, p3;

void preorder(int n)
{
    if(n == 0) return;
    p1.push_back(n);
    preorder(v[n].first);
    preorder(v[n].second);
}

void inorder(int n)
{
    if(n == 0) return;
    inorder(v[n].first);
    p2.push_back(n);
    inorder(v[n].second);
}

void postorder(int n)
{
    if(n == 0) return;
    postorder(v[n].first);
    postorder(v[n].second);
    p3.push_back(n);
}

int main()
{
    int n;
    scanf("%d", &n);
    char t;
    for(int i = 1; i <= n; i++)
    {
        char a, b, c;
        scanf("%c", &t);
        scanf("%c %c %c", &a, &b, &c);
        a -= 'A' - 1;
        b -= 'A' - 1;
        c -= 'A' - 1;
        if(b < 1) b = 0;
        if(c < 1) c = 0;
        v[a] = { b, c };
    }

    preorder(1);
    inorder(1);
    postorder(1);

    for(int i = 0; i < p1.size(); i++) printf("%c", p1[i] + 'A' - 1);
    puts("");
    for(int i = 0; i < p2.size(); i++) printf("%c", p2[i] + 'A' - 1);
    puts("");
    for(int i = 0; i < p3.size(); i++) printf("%c", p3[i] + 'A' - 1);
}
