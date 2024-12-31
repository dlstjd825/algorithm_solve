#include <iostream>
#include <algorithm>
using namespace std;

int ary[9];

int abs(int a, int b) {
	return a > b ? a - b : b - a;
}

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> ary[i];
	}

	sort(ary, ary + n);

	int rst = 0;

	do {
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			sum += abs(ary[i] - ary[i + 1]);
		}
		rst = rst > sum ? rst : sum;
	} while (next_permutation(ary, ary + n));

	cout << rst;
}