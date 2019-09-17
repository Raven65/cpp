//#define tx_ex2
#ifdef tx_ex2
#include <iostream>
#include <cmath>

using namespace std;


int main() {
	int n;
	cin >> n;
	long long ans = 0;
	long long cur = 0;
	while (n--) {
		int A;
		cin >> A;
		cur += A;
		ans += abs(cur);
	}
	cout << ans;
	return 0;
}
#endif // tx_ex
