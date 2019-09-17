//#define pdd_ex2
#ifdef pdd_ex2

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string input;
	cin >> input;
	vector<int> cnt(256, 0);
	vector<bool> visited(256, false);
	for (size_t i = 0; i != input.size(); ++i) {
		input[i] = tolower(input[i]);
	}
	for (char c : input)
		cnt[c]++;
	string result = "0";
	for (char c : input) {
		cnt[c]--;
		if (visited[c]) continue;
		while (c < result.back() && cnt[result.back()]) {
			visited[result.back()] = false;
			result.pop_back();
		}
		result += c;
		visited[c] = true;
	}
	cout << result.substr(1)[0];
	return 0;
}
#endif