//#define hw_2_ex3
#ifdef hw_2_ex3
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	unordered_map<int, int> mp;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		mp[x] = i;
	}
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		v[i] = mp[x];
	}
	
	vector<int> ans;
	for (int n : v) {
		auto pos = lower_bound(ans.begin(), ans.end(), n);
		if (pos == ans.end()) ans.push_back(n);
		else *pos = n;
	}
	cout << N - ans.size() << endl;

	return 0;
}
#endif