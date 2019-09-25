//#define pdd_2_ex3
#ifdef pdd_2_ex3
#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ll;
int main()
{
	int n, m;
	ll k;
	cin >> n >> m >> k;
	vector<vector<ll>> v(n + 1, vector<ll>(m + 1));
	for (int i = 0; i < n + 1; ++i) v[i][0] = i;
	for (int j = 0; j < m + 1; ++j) v[0][j] = j;
	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < m + 1; ++j)
			if (v[i - 1][j] >= 1e15 || v[i][j - 1] >= 1e15 ) v[i][j] = 1e15+1;
			else v[i][j] = v[i - 1][j] + v[i][j - 1] + 2;
	}

	while (k >0 && n > 0 && m > 0) {
		ll cut = v[n - 1][m] + 1;
		if (k <= cut || cut == 1e15+1) {
			cout << 'a';
			n--;
		}
		else {
			cout << 'b';
			m--;
			k -= cut;
			
		}
		k -= 1;
	}
	while (k--) cout << ((m == 0) ? 'a' : 'b');
	return 0;
}
#endif