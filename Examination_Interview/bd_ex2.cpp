//#define bd_2_ex2
#ifdef bd_2_ex2
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;
string a, b;
void getDp(vector<vector<int>>& dp, int l, int r) {
	if (dp[l][r] != -1) cout << dp[l][r] << endl;
	else {
		if (dp[l + b.size()][r] == -1) getDp(dp, l, l + b.size() - 1);
		if (dp[l][r - b.size()] == -1) getDp(dp, r - b.size() + 1, r);
		if (a.substr(l, b.size()) == b ) {
			dp[l][r] = max(dp[l][r], dp[l][l + b.size() - 1]+1);
		}
		else if(a.substr(r - b.size() + 1, b.size()) ==£» b)
			dp[l][r] = max(dp[l][r], dp[r - b.size() + 1][r]+1);
		else {
			dp[l][r] = max(dp[l][l + b.size() - 1], dp[r - b.size() + 1][r]);
		}
		cout << dp[l][r] << endl;
	}
	
}
int main() {

	cin >> a;
	cin >> b;
	int N;
	cin >> N;
	vector<vector<int>> dp(a.size()+1, vector<int>(a.size()+1, -1));
	for (int i = 1; i < a.size()+1; i++) {
		for (int j = 0; j < b.size() - 1; j++) {
			dp[i][i + j] = 0;
		}
	}
	while (N--) {
		int l, r;
		cin >> l >> r;
		getDp(dp, l, r);
	}

	return 0;
}

#endif