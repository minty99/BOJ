#include <cstdio>
#include <cstring>
#include <cstdlib>

int w;
char s[80000];

void fail(int code = 0)
{
    printf("-1");
    // if(code > 0) printf("errcode = %d\n", code);
    exit(0);
}
int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &w);
    char t[80000];
    gets(t);
    gets(t);
    int len = strlen(t);
    int ptr = 1;
    for(int i = 0; i < len; i++)
    {
        if(t[i] != ' ') s[ptr++] = t[i];
    }

    ptr--;  // ptr: length of s
    int count_g1 = 0;   // count of ()
    int count_g2 = 0;   // count of []
    int count_L = 0;
    int count_B = 0;
    bool well_terminated = false;
    for(int i = 1; i <= ptr; i++)
    {
        switch(s[i])
        {
            case 'S':
                switch(s[i-1])
                {
                    case ',':
                    case '[':
                    case '(':
                        break;
                    default:
                        if(i == 1) break;
                        fail(1);
                }
                switch(s[i+1])
                {
                    case ')':
                    case ']':
                    case ',':
                        break;
                    default:
                        if(i == ptr) { well_terminated = true; break; }
                        fail(2);
                }
                break;

            case 'L':
                switch(s[i-1])
                {
                    case ',':
                    case '[':
                    case '(':
                        break;
                    default:
                        if(i == 1) break;
                        fail(3);
                }
                switch(s[i+1])
                {
                    case '(':
                    case '[':
                        break;
                    default: fail(4);
                }
                count_L++;
                break;

            case 'B':
                switch(s[i-1])
                {
                    case ',':
                    case '[':
                    case '(':
                        break;
                    default:
                        if(i == 1) break;
                        fail(5);
                }
                switch(s[i+1])
                {
                    case '(':
                    case '[':
                        break;
                    default: fail(6);
                }
                count_B++;
                break;

            case ',':
                switch(s[i-1])
                {
                    case 'S':
                    case 'B':
                    case 'L':
                    case ')':
                    case ']':
                        break;
                    default: fail(7);
                }

                switch(s[i+1])
                {
                    case 'S':
                    case 'B':
                    case 'L':
                        break;
                    default: fail(8);
                }
                if(i == 1) fail(9);
                break;

            case '(':
                switch(s[i-1])
                {
                    case 'L':
                    case 'B':
                        break;
                    default: fail(10);
                }

                switch(s[i+1])
                {
                    case 'S':
                    case 'L':
                    case 'B':
                    case '(':
                    case '[':
                        break;
                    default: fail(11);
                }
                count_g1++;
                if(i == 1) fail(12);
                break;

            case ')':
                switch(s[i-1])
                {
                    case 'S':
                    case ')':
                    case ']':
                        break;
                    default: fail(13);
                }

                switch(s[i+1])
                {
                    case ',':
                    case ')':
                    case ']':
                        break;
                    default:
                        if(i == ptr) { well_terminated = true; break; }
                        else fail(14);
                }
                count_g1--;
                if(i == 1) fail(15);
                break;

            case '[':
                switch(s[i-1])
                {
                    case 'S':
                    case 'L':
                    case 'B':
                        break;
                    default: fail(16);
                }

                switch(s[i+1])
                {
                    case 'S':
                    case 'L':
                    case 'B':
                    case '(':
                    case '[':
                        break;
                    default: fail(17);
                }
                count_g2++;
                if(i == 1) fail(18);
                break;

            case ']':
                switch(s[i-1])
                {
                    case 'S':
                    case 'L':
                    case 'B':
                    case ')':
                    case ']':
                        break;
                    default: fail(19);
                }

                switch(s[i+1])
                {
                    case ',':
                    case ')':
                    case ']':
                        break;
                    default:
                        if(i == ptr) { well_terminated = true; break; }
                        else fail(20);
                }
                count_g2--;
                if(i == 1) fail(21);
                break;

            default: fail(22);
        }
        if(count_g1 < 0 || count_g2 < 0) fail(23);
    }

    if(count_g1 == 0 && count_g2 == 0 && well_terminated) printf("%d", count_B + w * count_L + 1);
    else fail(24);
}
