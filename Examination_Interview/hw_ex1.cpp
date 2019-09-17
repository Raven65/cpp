//#define hw_ex1
#ifdef hw_ex1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void process(string ip_s, vector<int> &ip) {
	int temp = 0;
	for (size_t i = 0; i != ip_s.size(); ++i) {
		if (ip_s[i] == '.') {
			ip.push_back(temp);
			temp = 0;
		}
		else {
			temp *= 10;
			temp += ip_s[i] - '0';
		}
	}
	ip.push_back(temp);
}
int main() {
	string ip_s1, ip_s2, mask_s;
	vector<int> ip1, ip2 ,mask;
	cin >> ip_s1 >> ip_s2 >> mask_s;
	process(ip_s1, ip1);
	process(ip_s2, ip2);
	process(mask_s, mask);
	int flag = 1;
	for (int i = 0; i != 4; ++i) {
		ip1[i] &= mask[i];
		ip2[i] &= mask[i];
		if (ip1[i] != ip2[i]) {
			flag = 0;
		}
	}
	cout << flag << " ";
	for (int i = 0; i != 4; ++i) {
		cout << ip1[i];
		if (i != 3) cout << '.';
	}
	return 0;
}

#endif