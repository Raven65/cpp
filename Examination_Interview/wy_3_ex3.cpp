//#define wy_3_ex3
#ifdef wy_3_ex3
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> h(n);
		vector<int> dp(n);
		dp[0] = 1;


		for (int i = 0; i < n; ++i) {
			cin >> h[i];
		}

		for (int i = 1; i < n; ++i) {
			for (int j = max(i - k, 0); j < i; ++j) {
				if (dp[j] == 1) {
					if (h[j] >= h[i]) {
						dp[i] = 1;
						break;
					}
					else dp[i] = -1;
				}
				else if (dp[j] == -1 && h[j] >= h[i]) dp[i] = -1;

			}
		}
		if (dp[n - 1] != 0) cout << "YES";
		else cout << "NO";



	}
	return 0;
}
#endif