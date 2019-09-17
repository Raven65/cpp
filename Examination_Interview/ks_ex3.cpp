//#define ks_ex3
#ifdef ks_ex3



#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
	}
	int sum = accumulate(nums.begin(), nums.end(), 0);
	vector<int> dp(sum/2 + 1);
	dp[0] = 1;
	for (int x : nums) {
		for (int i = sum/2; i >= x; i--) {
			dp[i] = dp[i] | dp[i - x];
		}
	}
	for (int i = sum / 2; i > 0; i--) {
		if (dp[i]) { cout << abs(2 * i - sum); break; }
	}
	return 0;
}

#endif // bilibili_ex1