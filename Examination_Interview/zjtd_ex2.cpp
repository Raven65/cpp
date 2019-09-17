//#define zjtd_ex2
#ifdef zjtd_ex2
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	int N;
	cin >> N;
	string s;
	
	while (N--) {
		cin >> s;
		string out;
		for (size_t i = 0; i != s.size(); ++i) {
			if (out.empty() || s[i] != out.back()) {
				out.push_back(s[i]);
				continue;
			}
			if (s[i] == out.back()) {
				int n = out.size()-1;

				if (n > 0 && out[n - 1] == out[n])
					continue;
				if (n > 1 && out[n - 1] != out[n] && out[n - 1] == out[n - 2])
					continue;
				out.push_back(s[i]);
					
			}
		}
		cout << out;
		if (N != 0) cout << endl;
	}
	return 0;
}
#endif