//#define tx_2_4
#ifdef tx_2_4
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	vector<long long> sum(n);
	vector<int> left(n), right(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum[i] = i > 0 ? sum[i - 1] + v[i] : v[i];
	}
	left[0] = -1;
	for (int i = 1; i < n; ++i) {
		int l = i - 1;
		while (l > -1 && v[l] >= v[i]) {
			l = left[l];
		}
		left[i] = l;
	}
	right[n - 1] = n;
	for (int i = n - 2; i > -1; --i) {
		int r = i + 1;
		while (r < n&&v[r] >= v[i]) {
			r = right[r];
		}
		right[i] = r;
	}
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		long long total = left[i] == -1 ? sum[right[i] - 1] : sum[right[i] - 1] - sum[left[i]];
		res = max(res, total*v[i]);
	}
	cout << res;



	return 0;
}
#endif