//#define wy_2_ex1
#ifdef wy_2_ex1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> nums;
	vector<int> dp;
	int n;
	while (cin >> n) {
		nums.push_back(n);
		getchar();
	}
	for (int& n : nums) {
		if (dp.empty() || n > dp.back()) dp.push_back(n);
		else {
			auto it = lower_bound(dp.begin(), dp.end(), n);
			*it = n;
		}
	}
	cout << dp.size();

	return 0;
}
#endif