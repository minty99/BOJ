#include <cstdio>
#include <algorithm>
using namespace std;

int state = 1;

int main()
{
    // freopen("in.txt", "r", stdin);

    int w, h, p, q, t;
    scanf("%d %d %d %d %d", &w, &h, &p, &q, &t);

    int k = 0;
    int x = p, y = q;
    while(k < t)
    {
        // printf("k = %d, t = %d, x = %d, y = %d\n", k, t, x, y);
        int c;
        switch (state)
        {
            case 1:
                // right, up
                c = min(w - x, h - y);
                c = min(c, t - k);
                x += c;
                y += c;
                k += c;
                if(x == w) state = 2;
                else state = 4;
                break;
            case 2:
                // left, up
                c = min(x, h - y);
                c = min(c, t - k);
                x -= c;
                y += c;
                k += c;
                if(x == 0) state = 1;
                else state = 3;
                break;
            case 3:
                // left, down
                c = min(x, y);
                c = min(c, t - k);
                x -= c;
                y -= c;
                k += c;
                if(x == 0) state = 4;
                else state = 2;
                break;
            case 4:
                // right, down
                c = min(w - x, y);
                c = min(c, t - k);
                x += c;
                y -= c;
                k += c;
                if(x == w) state = 3;
                else state = 1;
                break;
        }

    }

    printf("%d %d", x, y);
}
