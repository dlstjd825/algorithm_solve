#include <iostream>

using namespace std;

int ary[9];
int current[9];
bool visited[9];
int N;
int rst;

int abs(int a, int b) {
    return a > b ? a - b : b - a;
}

void sum_diff() {
    int total = 0;
    for (int i = 0; i < N - 1; i++) {
        int sum = abs(current[i] - current[i + 1]);
        total += sum;
    }
    rst = rst > total ? rst : total;
}

void dfs(int depth) {
    if (depth == N) {
        sum_diff();
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            current[depth] = ary[i];
            dfs(depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> ary[i];
    }

    dfs(0);

    cout << rst;

    return 0;
}