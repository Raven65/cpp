//#define ks_ex4
#ifdef ks_ex4



#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	int N;
	cin >> N;
	if (N < 2) {
		cout << N;
		return 0;
	}
	vector<int> nums(N);
	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	int max_diff = nums.back() - nums.front();
	vector<vector<int>> dp(max_diff+1, vector<int>(N, 1));
	int res = 2;
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			int diff = nums[i] - nums[j];
			dp[diff][i] = dp[diff][j] + 1;
			res = max(res, dp[diff][i]);
		}
	}
	cout << res;

	return 0;
}

#endif // bilibili_ex1