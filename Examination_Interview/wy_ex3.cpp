//#define wy_ex3
#ifdef wy_ex3

#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
#define N 310
#define LL long long
#define INF 0xfffffff
const double eps = 1e-8;
const double pi = acos(-1.0);
const double inf = ~0u >> 2;
struct point
{
	double x, y;
	point(double x = 0, double y = 0) :x(x), y(y) {}
} p[N];
struct node
{
	double ang;
	int in;
} arc[N*N];
double dis(point a, point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
int dcmp(double x)
{
	if (fabs(x) < eps)return 0;
	else return x < 0 ? -1 : 1;
}
bool cmp(node a, node b)
{
	if (dcmp(a.ang - b.ang) == 0)
		return a.in > b.in;
	return dcmp(a.ang - b.ang) < 0;
}
int main()
{
	int i, j, n;
	int T;
	double r;
	cin >> T;
	while (T--)
	{
		cin >> n >> r;
		for (i = 1; i <= n; i++)
			cin>>p[i].x>>p[i].y;
		int g = 0;
		int ans = 0, maxz = 1;
		for (i = 1; i <= n; i++)
		{
			ans = 0;
			g = 0;
			for (j = 1; j <= n; j++)
			{
				if (dis(p[i], p[j]) > 2*r) continue;
				double ang1 = atan2(p[j].y - p[i].y, p[j].x - p[i].x);
				double ang2 = acos(dis(p[i], p[j]) / (2*r));
				arc[++g].ang = ang1 - ang2;//这里角度的算法很巧妙
				arc[g].in = 1;
				arc[++g].ang = ang1 + ang2;
				arc[g].in = -1;
			}
			sort(arc + 1, arc + g + 1, cmp);

			//cout<<g<<endl;
			for (j = 1; j <= g; j++)
			{
				ans += arc[j].in;
				maxz = max(maxz, ans);
			}
		}
		cout << maxz << endl;
	}
	return 0;
}
#endif