//#define al_ex1
#ifdef al_ex1
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<double> prob(n);
	long double ans = 0;
	long double pre = 1;
	for (int i = 0; i < n; ++i) {
		cin >> prob[i];
	}
	for (int i = 0; i < 100; ++i) {
		long double p = prob[i%n];
		if (i % 2 == 0) {
			ans += pre * p;
			pre *= (1 - p);
		}
		else {
			pre *= (1 - p);
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(4) << ans;
	
	return 0;
}
#endif // tx_ex
