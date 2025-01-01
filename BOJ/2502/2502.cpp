#include <iostream>

using namespace std;

int main() {
    int d, k;
    cin >> d >> k;

    int x[32];

    x[0] = 0;
    x[1] = 1;
    x[2] = 0;

    for (int i = 3; i < d + 2; i++) {
        x[i] = x[i - 1] + x[i - 2];
    }

    int p = x[d];       // a의 계수
    int q = x[d + 1];   // b의 계수

    for (int a = 1; a <= k / p; a++) {
        for (int b = 2; b <= k / q; b++) {
            if (p * a + q * b == k) {
                cout << a << endl << b;
                return 0;
            }
        }
    }
}