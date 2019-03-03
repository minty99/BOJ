#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <random>
#include <functional>
#include <array>
#define x first
#define y second
using namespace std;

typedef long long int lli;

int r[600][600], g[600][600], b[600][600];
double avg[3];
double s[4][3];
int h, w;

void input(int arr[][600], double *sum)
{
    *sum = 0;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
        {
            scanf("%d", &arr[i][j]);
            *sum += arr[i][j];
        }
    *sum /= (double) h*w;
}

double calc_p3()
{
    int tM = 100;
    mt19937 engine;
    uniform_int_distribution<int> d1(5, h-5);
    uniform_int_distribution<int> d2(5, w-5);
    auto gen1 = bind(d1, engine);
    auto gen2 = bind(d2, engine);
    int pass = 0;    // max: 5000
    for(int t = 1; t <= tM; t++)
    {
        // randomized 5x5 area.
        int cx = gen1();
        int cy = gen2();

        int Mr = 0, Mg = 0, Mb = 0;
        int mr = 2e9, mg = 2e9, mb = 2e9;
        for(int i = cx - 5; i < cx + 5; i++)
        {
            for(int j = cy - 5; j < cy + 5; j++)
            {
                Mr = max(Mr, r[i][j]);
                mr = min(mr, r[i][j]);
                Mg = max(Mg, g[i][j]);
                mg = min(mg, g[i][j]);
                Mb = max(Mb, b[i][j]);
                mb = min(mb, b[i][j]);
            }
        }
        if(Mr - mr >= 100 and Mg - mg >= 100 and Mb - mb >= 100) pass++;
    }

    pass /= 5;
    double p3 = pass * pass;
    return p3;
}

double classify()
{
    double tot_diff = 0;
    for(int i = 5; i < h-6; i++)
    {
        for(int j = 5; j < w-6; j++)
        {
            for(int k = i-5; k < i+5; k += 5)
            {
                for(int l = j-5; l < j+5; l += 5)
                {
                    if(k == i and l == j) continue;
                    int d1 = r[k][l] - r[i][j];
                    int d2 = g[k][l] - g[i][j];
                    int d3 = b[k][l] - b[i][j];
                    tot_diff += abs(d1) + abs(d2) + abs(d3);
                }
            }
        }
    }

    return (double) tot_diff / (h*w);
}

double classify_12()
{
    int cnt = 0;
    for(int i = 10; i < h-11; i++)
    {
        for(int j = 10; j < w-11; j++)
        {
            for(int k = i-10; k < i+11; k += 4)
            {
                for(int l = j-10; l < j+11; l += 4)
                {
                    if(k == i and l == j) continue;
                    if((abs(r[k][l] + g[k][l] + b[k][l]) - abs(r[i][j] + g[i][j] + b[i][j]) >= 500)) cnt += 30;
                }
            }
        }
    }
    return (double) cnt / (h*w);
}

int main()
{
    #ifndef ONLINE_JUDGE
    setbuf(stdout, NULL);
    for(int x = 1; x <= 4; x++)
    {
        puts("");
        for(int y = 1; y <= 9; y++)
        {
            string st = "./ArtClass/style-";
            st += x + '0';
            st += '-';
            st += y + '0';
            st += ".in";
            freopen(st.c_str(), "r", stdin);
    #endif
            scanf("%d %d", &h, &w);
            input(r, &avg[0]);
            input(g, &avg[1]);
            input(b, &avg[2]);

            double p3 = calc_p3();
            //double M = max(max(max(p1, p2), p3), p4);

            #ifndef ONLINE_JUDGE
            printf("%d-%d: ", x, y);
            #endif

            // clsfy: 색이 다양한 경우 크게 나옴
            double clsfy = classify();
            // clsfy12: 매우 유사하거나, 또는 아주 크게 다른 점이 많으면 크게 나옴
            double clsfy12 = classify_12();

            if(clsfy > 290 and p3 >= 120) printf("3");
            else if(clsfy < 65) printf("4");
            else if(clsfy12 > 3) printf("1");
            else printf("2");

    #ifndef ONLINE_JUDGE
            printf(" p3: %f, clsfy: %f, clsfy12: %f", p3, clsfy, clsfy12);
            puts("");
        }
    }
    #endif

}
