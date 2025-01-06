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

    for (int a = 0; a < 9; a++) {
        for (int b = a + 1; b < 9; b++) {
            for (int c = b + 1; c < 9; c++) {
                for (int d = c + 1; d < 9; d++) {
                    for (int e = d + 1; e < 9; e++) {
                        for (int f = e + 1; f < 9; f++) {
                            for (int g = f + 1; g < 9; g++) {
                                if (height[a] + height[b] + height[c] + height[d] + height[e] + height[f] + height[g] == 100) {
                                    cout << height[a] << endl;
                                    cout << height[b] << endl;
                                    cout << height[c] << endl;
                                    cout << height[d] << endl;
                                    cout << height[e] << endl;
                                    cout << height[f] << endl;
                                    cout << height[g] << endl;
                                    return 0;
                                }
                            }

                        }
                    }
                }
            }
        }
    }
}




