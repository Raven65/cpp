//#define bilibili_ex2
#ifdef bilibili_ex2



#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{

	int n, s;
	cin >> n >> s;
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	int sum = 0;
	int res = INT_MAX;
	deque<int> path;
	for (int x : p) {

		path.push_back(x);
		sum += x;
		while (!path.empty() && sum >= s) {
			res = min(res, (int)path.size());
			sum -= path.front();
			path.pop_front();
		}

	}
	cout << ((res == INT_MAX) ? 0 : res) << endl;

	
	return 0;
}

#endif // bilibili_ex1