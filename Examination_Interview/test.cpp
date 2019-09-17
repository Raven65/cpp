#include <iostream>

using namespace std;
int main() {
	int n = 2048;
	cout << (n & -n);
	return 0;
}