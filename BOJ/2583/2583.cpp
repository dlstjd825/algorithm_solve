#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int n, m;
int board[101][101]; 
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int area[10001];
int cnt = 0;

queue<tuple<int, int>> q;

void bfs(int x, int y) {
	board[y][x] = 1;
	area[cnt] = 1;
	q.push(make_tuple(y, x));  // 좌표를 튜플로 저장하고 큐에 넣기

	while (!q.empty()) {
		int cy = get<0>(q.front());  // 큐의 첫 번째 원소(튜플)의 첫 번째 값 반환
		int cx = get<1>(q.front());  // 큐의 첫 번째 원소(튜플)의 두 번째 값 반환

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if ((0 <= nx && nx < n) && (0 <= ny && ny < m) && board[ny][nx] != 1) {
				board[ny][nx] = 1;
				area[cnt]++;  // 현재 세고있는 영역의 넓이 +1
				q.push(make_tuple(ny, nx));  // 새로운 좌표를 튜플로 만들어서 넣기
			}
		}
	}
}

int main() {
	int k;
	cin >> m >> n >> k;

	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				board[y][x] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] != 1) {
				bfs(j, i);  
				cnt += 1;  // bfs탐색이 끝나면 직사각형으로 막힌거임 => 영역 개수 증가
			}
		}
	}

	cout << cnt << endl;

	sort(area, area + cnt);

	for (int i = 0; i < cnt; i++) {
		cout << area[i] << " ";
	}

	return 0;
}