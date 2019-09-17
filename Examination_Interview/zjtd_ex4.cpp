//#define zjtd_ex4
#ifdef zjtd_ex4
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#define MAX_LOOP 300
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<double> rope(N);
	double mini = INT_MAX, maxi = INT_MIN;
	for(int i = 0;i!=N;++i) {
		cin >> rope[i];
		mini = min(rope[i], mini);
		maxi = max(rope[i], maxi);
	}
	double l = (M <= N) ? mini : 0;
	double r = (M <= N) ? maxi : 1e9;
	for (int j = 0; j < MAX_LOOP; ++j) {
		double mid = (l + r) / 2;
		int count = 0;
		for (int i = 0; i < N; ++i)
		{
			count += (int)(rope[i] / mid);
		}
		(count >= M )?  l = mid : r = mid;

	}
	printf("%.2lf\n", floor(l * 100) / 100);



	return 0;
}
#endif
