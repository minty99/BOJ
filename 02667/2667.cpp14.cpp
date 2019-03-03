// DFS를 사용해서 풀 수 있는 문제입니다.
#include <cstdio>
#include <algorithm>

using namespace std;
int n;
int arr[26][26];
int cnt[700];

void DFS(int x, int y, int num)
{
    arr[x][y] = num;
    cnt[-num]++;
    if(x - 1 >= 0 && arr[x-1][y] == 1) DFS(x-1, y, num);
    if(x + 1 < n && arr[x+1][y] == 1) DFS(x+1, y, num);
    if(y - 1 >= 0 && arr[x][y-1] == 1) DFS(x, y-1, num);
    if(y + 1 < n && arr[x][y+1] == 1) DFS(x, y+1, num);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        char s[40];
        scanf("%s", s);
        for(int j = 0; j < n; j++) arr[i][j] = s[j] - '0';
    }

    int num = 0;    // 이미 arr배열은 0과 1로 채워져있으니, 탐색한 후에는 음수로 바꿔서 표시한다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(arr[i][j] == 1) DFS(i, j, --num);

    printf("%d\n", -num);
    sort(cnt+1, cnt+(-num)+1);
    for(int i = 1; i < (-num)+1; i++) printf("%d\n", cnt[i]);
}
