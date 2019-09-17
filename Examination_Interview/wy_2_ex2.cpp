//#define wy_2_ex2
#ifdef wy_2_ex2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void dfs(vector<int>& nums, vector<vector<int>>& ans, int index, int target, vector<int>& ret);
int main() {
	vector<int> nums;
	int n;
	int target;
	cin >> target;
	getchar();
	while (cin >> n) {
		nums.push_back(n);
		getchar();
	}
	sort(nums.begin(), nums.end());
	vector<vector<int>> ans;
	vector<int> ret;
	dfs(nums, ans, 0, target, ret);
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < 4; ++j)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	
	cout << ans.size();
		
	

	return 0;
}
void dfs(vector<int>& nums, vector<vector<int>>& ans, int index, int target, vector<int>& ret) {
	if (ret.size() == 4 && target == 0) { ans.push_back(ret); return; }
	if (index >= nums.size()) return;
	for (int i = index; i < nums.size(); ++i) {
		if (nums[i] > 0 && target < 0) break;
		if (i == index || nums[i] != nums[i - 1]) {
			ret.push_back(nums[i]);
			dfs(nums, ans, i + 1, target - nums[i], ret);
			ret.pop_back();
		}
		
	}
}
#endif