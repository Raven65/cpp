//#define mt_ex1
#ifdef mt_ex1

#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
#include <algorithm>
using namespace std;



int findMost(unordered_map<int, int> m) {
	int max = INT_MIN;
	int res = INT_MIN;
	for (auto it = m.begin(); it != m.end(); ++it) {
		if (it->second > max) { res = it->first; max = it->second; }
	}
	return res;
}
int findSecond(unordered_map<int, int> m) {
	int max = INT_MIN;
	int second = INT_MIN;
	int maxRes = INT_MIN;
	int res = INT_MIN;
	for (auto it = m.begin(); it != m.end(); ++it) {
		if (it->second > max) {
			res = maxRes;
			second = max;
			max = it->second;
			maxRes = it->first;
		}
		else if (it->second > second) {
			res = it->first;
			second = it->second;
		}
	}
	return res;
}
int main() {
	int m, n;
	cin >> n >> m;
	int ans = 0;
	int flag = 0;
	unordered_map<int, int> m1;
	unordered_map<int, int> m2;
	int count1 = 0, count2 = 0;
	vector<vector<int>> input(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> input[i][j];
			if (!flag) { ++m1[input[i][j]]; flag = 1; ++count1; }
			else { ++m2[input[i][j]]; flag = 0; ++count2; }
		}
	int x1 = findMost(m1);
	int x2 = findMost(m2);
	if (x1 != x2) { ans = (count1 - m1[x1]) + (count2 - m2[x2]); }
	else {
		if ((count1 - m1[x1]) < (count2 - m2[x2]) && m2.size() > 1) {
			x2 = findSecond(m2);	
			ans = (count1 - m1[x1]) + (count2 - m2[x2]);
		}
		else if((count1 - m1[x1]) > (count2 - m2[x2]) && m1.size() > 1){
			x1 = findSecond(m1);
			ans = (count1 - m1[x1]) + (count2 - m2[x2]);
		}
		else if (m1.size() == 1 && m2.size()>1) {
			ans = count1 + (count2 - m2[x2]);
			x2 = findSecond(m2);
			ans = min(ans, count2 - m2[x2]);
		}
		else if (m2.size() == 1 && m1.size() > 1) {
			ans = count2 + (count1 - m1[x1]);
			x1 = findSecond(m1);
			ans = min(ans, count1 - m1[x1]);
		}
		else if (m1.size() == 1 && m2.size() == 1) {
			ans = min(count1, count2);
		}

		
	}
	cout << ans;
	

		
	return 0;
}
#endif