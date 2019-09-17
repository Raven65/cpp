//#define hw_2_ex2
#ifdef hw_2_ex2
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	string out;
	vector<string> res;
	vector<int> map(256, 0);
	for (char ch : s) {
		map[ch]++;
	}
	while (1) {
		int flag = 0;
		for (char i = 97; i != 123; ++i) {
			if (map[i] > 0 && map[i - 32] > 0) {
				flag = 1;
				map[i - 32]--;
				map[i]--;
				out.push_back(i - 32);
				out.push_back(i);
				
			}
			else {
				if(out.empty()) continue;
				sort(out.begin(), out.end(), [](char c1, char c2) {return (abs(c1 - c2) == 32) ? c1 < c2 : tolower(c1) < tolower(c2); });
				res.push_back(out);
				out = string();
			}
		}
		if (!flag) break;
	}
	sort(res.begin(), res.end(), [](string &s1, string &s2) {return (s1[0] == s2[0]) ? s1.size() > s2.size() :s1 < s2; });
	for (string &s : res) cout << s << endl;
	if (res.empty()) cout << "Not Found";
	
	return 0;
}

#endif