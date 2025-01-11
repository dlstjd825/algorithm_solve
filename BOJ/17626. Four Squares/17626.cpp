#include <iostream>
#include <cmath>
#define MAX 100000
using namespace std;

int dp[50000];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        dp[i] = MAX;
    }

    for (int i = 1; i <= sqrt(50000); i++) {
        dp[i * i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (dp[i] == 1) continue;

        for (int j = 1; j * j < i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[n];
}