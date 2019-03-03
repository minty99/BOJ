#include <stdio.h>
 
int main()
{
  int t;
  scanf("%d", &t);
  for(int i = 1; i <= t; i++)
  {
    int m, n, x, y;
    scanf("%d %d %d %d", &m, &n, &x, &y);
    int a = 1, b = 1, count = 1;
    while(true)
    {
      if(a == x && b == y)
      {
        printf("%d\n", count);
        break;
      }
 
      if(a == m && b == n)
      {
        printf("-1\n");
        break;
      }
 
      a++;
      b++;
      count++;
      if(a > m) a = 1;
      if(b > n) b = 1;
      while((a == 1 || b == 1) && (a - b != x - y))
      {
        int min = m-a < n-b ? m-a : n-b;
        a += min+1;
        b += min+1;
        count += min+1;
        if(a > m) a -= m;
        if(b > n) b -= n;
        if(a == 1 && b == 1) 
        {
          a = m;
          b = n;
          break;
        }
      }
    }
  }
}