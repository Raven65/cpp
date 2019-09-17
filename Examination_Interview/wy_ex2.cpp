//#define wy_ex2
#ifdef wy_ex2
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int checkShift(char x, unordered_map<char, vector<char>> &rule, unordered_set<char> &broken) {
	if (broken.find(x) == broken.end()) return 1;
	if (rule.find(x) == rule.end()) return -1;
	int minCount;
	for (int i = 0; i != rule[x].size(); ++i) {
		int count = checkShift(rule[x][i], rule, broken);
		if (i == 0) minCount = count;
		else minCount = (count < minCount) ? count: minCount;
	}
	if (minCount == -1) return -1;
	else return 1 + minCount;
	
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		unordered_map<char, vector<char>> rule;
		while (N--) {
			char x, y;
			cin >> x >> y;
			rule[y].push_back(x);
		}
		int M;
		cin >> M;
		unordered_set<char> broken;
		while (M--) {
			char x;
			cin >> x;
			broken.insert(x);
		}
		string text;
		cin >> text;
		int count = 0;
		for (int i = 0; i != text.size(); ++i) {
			int countTemp = checkShift(text[i], rule, broken);
			if (countTemp == -1) {
				count = -1; break;
			}
			else {
				count += countTemp;
			}
			
		}
		cout << count << endl;

	}
	return 0;
}
#endif