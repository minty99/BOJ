#include <cstdio>
#include <string>

char map[64][64];
typedef std::string String;
String QuadTree(int x1, int y1, int x2, int y2);
char check(int x1, int y1, int x2, int y2);

int main()
{
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
			scanf("%s", map[i]);
	printf("%s", QuadTree(0, 0, n-1, n-1).c_str());
}

String QuadTree(int x1, int y1, int x2, int y2)
{
	char c = check(x1, y1, x2, y2);
	int x_half = (x1+x2)/2;
	int y_half = (y1+y2)/2;
	if(c >= 0) return String(1, c);
	// (0, 0, 3, 3) (0, 4, 3, 7) (4, 0, 7, 3) (4, 4, 7, 7)
	else return "(" + QuadTree(x1, y1, x_half, y_half) + QuadTree(x1, y_half+1, x_half, y2)
				+ QuadTree(x_half+1, y1, x2, y_half) + QuadTree(x_half+1, y_half+1, x2, y2) + ")";
}

char check(int x1, int y1, int x2, int y2)
{
	char base = map[x1][y1];
	for(int i = x1; i <= x2; i++)
		for(int j = y1; j <= y2; j++)
			if(base != map[i][j]) return -1;
	return base;
}
