//#define bilibili_ex1
#ifdef bilibili_ex1



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream> 
using namespace std;

int main()
{
	vector<string> nums;
	string input;
	cin >> input;
	stringstream ss(input);
	string n;
	while (getline(ss,n,',')) {
		nums.push_back(n);
	}
	auto cmp = [](string m, string n)->bool {
		return (m + n) > (n + m);

	};
	sort(nums.begin(), nums.end(), cmp);
	if (nums.empty() || nums[0] == string("0")) cout << string("0");
	else {
		string ans;
		for (string& n : nums)
			ans += n;
		cout << ans;
	}
	return 0;
}

#endif // bilibili_ex1