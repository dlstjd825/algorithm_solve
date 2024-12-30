#include <iostream>
#define M 1000000007

using namespace std;

int main() {
	long long dp[10001];

	dp[0] = 1;
	dp[3] = 3;

	for (int i = 6; i < 10001; i += 3) {
		dp[i] = (3 * (dp[i - 3] % M)) % M;
		long long temp = 0;
		for (int j = 2; j <= i / 3; j++) {
			temp = (temp + (2 % M) * (j % M) % M * (dp[i - 3 * j] % M) % M) % M;
		}
		dp[i] = (dp[i] % M + temp % M) % M;
	}

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		if (n % 3 != 0) {
			cout << 0 << endl;
		}
		else {
			cout << dp[n] % M << endl;
		}
	}

}