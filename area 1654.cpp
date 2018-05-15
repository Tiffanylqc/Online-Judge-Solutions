#include<cstdio>
const int dx[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1};
const int dy[] = { -1, -1, -1, 0, 0, 0, 1, 1, 1};

char s[1000005];

int main()
{
	int T, x, y, i, dir;
	long long area;
	scanf("%d\n", &T);
	while (T--)
	{
		gets(s);
		x = y = 0;
		area = 0;
		for (i = 0; s[i]; ++i)
		{
			dir = s[i] - '1';
			area += x * dy[dir] - y * dx[dir];
			x += dx[dir];
			y += dy[dir];
		}
		if (area < 0) area = -area;
		if (area & 1) printf("%lld.5\n", area >> 1);
		else printf("%lld\n", area >> 1);
	}
	return 0;
}
