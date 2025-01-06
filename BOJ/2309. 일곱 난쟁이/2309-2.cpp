#include <iostream>

using namespace std;

int main() {
    int height[9];

    for (int i = 0; i < 9; i++) {
        cin >> height[i];
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 1; j < 9 - i; j++) {
            if (height[j] < height[j - 1]) {
                int temp = height[j];
                height[j] = height[j - 1];
                height[j - 1] = temp;
            }
        }
    }

    int sum = 0;

    for (int i = 0; i < 9; i++) {
        sum += height[i];
    }

    int diff = sum - 100;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (height[i] + height[j] == diff) {
                for (int k = 0; k < 9; k++) {
                    if (k != i && k != j) {
                        cout << height[k] << endl;
                    }
                }
                return 0;
            }
        }
    }
}
