#include <cstdio>
#include <vector>    // C++ vector

using namespace std;

// 구조체
struct Circle {
    int x, y, r;
};

struct Point {
    int x, y;
};

bool isIn(Circle c, Point p)
{
    int r2 = (p.x - c.x) * (p.x - c.x) + (p.y - c.y) * (p.y - c.y);
    int cr2 = c.r*c.r;
    if(r2 < cr2) return true;
    else return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {
        Point a, b;
        int n;
        scanf("%d %d %d %d", &a.x, &a.y, &b.x, &b.y);
        scanf("%d", &n);
        vector<Circle> c;
        for(int j = 1; j <= n; j++)
        {
            Circle cc;
            scanf("%d %d %d", &cc.x, &cc.y, &cc.r);
            c.push_back(cc);
        }

        int answer = n;    // 두 지점을 감싸는 원의 갯수가 기본적으로 답이 된다.
        // 다만 두 점이 동시에 속한 원은 이탈할 필요가 없으므로 답이 되지 않는다.

        for(int j = 0; j < n; j++)
        {
            if(isIn(c[j], a) == isIn(c[j], b)) answer--;
        }
        printf("%d\n", answer);
    }
}
