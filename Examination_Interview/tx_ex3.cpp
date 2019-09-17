//#define tx_ex3
#ifdef tx_ex3
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	int x = 0;
	x = ceil(log2(ceil((float)n / k))) + k;
	cout << x;
	priority_queue<int, std::vector<int>, std::greater<int>> pq;
	while (n--) {
		int num;
		cin >> num;
		pq.push(num);
	}
	long long sum = 0;
	while (k--) {
		long long cur = long long(pq.top()) - sum;
		if (cur < 0) cout << 0 << endl;
		else cout << cur << endl;
		pq.pop();
		sum += cur;
		
	}
	return 0;
}
#endif // tx_ex
