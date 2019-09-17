//#define pdd_ex4
#ifdef pdd_ex4
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
bool isValid(const string &s) {
	stack<char> check;
	for (const char& c : s) {
		switch (c) {
		case '(': check.push(c); break;
		case ')': if (check.empty() || check.top() != '(') return false; else check.pop(); break;
		default:;
		}
	}
	return check.empty();
}
void generate(vector<string> &gen, string &s1, string &s2) {
	vector<string> temp;
	vector<pair<size_t, size_t>> index;
	temp.push_back("");
	index.push_back(make_pair(0, 0));
	int index1 = 0, index2 = 0;
	for (size_t i = 0; i < s1.size() + s2.size(); ++i) {
		vector<string> new_temp;
		vector<pair<size_t, size_t>> new_index;
		for (size_t j = 0; j < temp.size(); ++j) {
			if (index[j].first < s1.size()) {
				new_temp.push_back(temp[j] + s1[index[j].first]);
				new_index.push_back(make_pair(index[j].first + 1, index[j].second));
			}
			if (index[j].second < s2.size()) {
				new_temp.push_back(temp[j] + s2[index[j].second]);
				new_index.push_back(make_pair(index[j].first, index[j].second + 1));
			}

		}
		temp = new_temp;
		index = new_index;
	}
	gen = temp;


}
int main() {
	string input1, input2;
	cin >> input1 >> input2;
	vector<string> gen_str;
	generate(gen_str, input1, input2);
	int cnt = 0;
	for (string &s : gen_str)
		if (isValid(s))
			cnt++;
	cout << cnt % int(pow(10, 9) + 7);
	return 0;
}
#endif
