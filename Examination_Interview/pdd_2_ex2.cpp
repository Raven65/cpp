#define pdd_2_ex2
#ifdef pdd_2_ex2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct point {
	int start;
	int end;
	bool operator<(point& p2) {
		return start < p2.start;
	}
};
int main()
{
	int n, m;
	cin >> n >> m;
	vector<point> v;
	while (m--) {
		point a;
		cin >> a.start >> a.end;
		v.push_back(a);
		sort(v.begin(), v.end());
		vector<point> tmp;
		for (auto& p : v) {
			if (tmp.empty() || p.start > tmp.back().end) tmp.push_back(p);
			else tmp.back().end = max(tmp.back().end, p.end);
		}
		int cnt = 0;
		for (auto& p : tmp) {
			cnt += (p.end - p.start + 1);
		}
		cout << cnt << endl;
		v.swap(tmp);
	}
	return 0;

}
#endif