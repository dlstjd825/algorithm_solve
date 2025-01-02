#include <iostream>
#include <map>

using namespace std;

int main() {
    int N, M;
    int cnt = 0;
    string s;
    cin >> N >> M;

    map<string, int> m;
    map<string, int>::iterator iter;

    for (int i = 0; i < N + M; i++) {
        cin >> s;
        m[s]++;
        if (m[s] == 2) cnt++;
    }

    cout << cnt << endl;

    for (iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second == 2) {
            cout << iter->first << endl;
        }
    }

    return 0;
}