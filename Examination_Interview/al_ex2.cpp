//#define al_ex2
#ifdef al_ex2
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
using namespace std;
unordered_set<string> ans;
void dfs(vector<int>& bowl, int m, int n, int index);
int main() {
	int m, n, k;
	cin >> m >> n >> k;
	vector<int> bowl(k, 0);
	dfs(bowl, m, n, 0);
	cout << ans.size()%10000;
	return 0;
}
void dfs(vector<int>& bowl, int m, int n, int index) {
	if (index == bowl.size()) return;
	if (m == 0 && n == 0) { 
		vector<int> temp(bowl);
		sort(temp.begin(), temp.end());
		string s;
		for (int i = 0; i < temp.size(); ++i) {
			s += to_string(temp[i]);
		}
		ans.insert(s);
		return; 
	}
	dfs(bowl, m, n, index + 1);
	if (m && bowl[index] >= 0 && bowl[index] < 50) {
		++bowl[index];
		dfs(bowl, m - 1, n, index);
		--bowl[index];
	}
	if (n && bowl[index] <= 0 && bowl[index] > -50) {
		--bowl[index];
		dfs(bowl, m, n - 1, index);
		++bowl[index];

	}
}
#endif // tx_ex
