#include <string>
#include <vector>
#include <queue>

using namespace std;

int board[105][105], dx[8] = { 0, 1, 0, -1, -1, 1, 1, -1 }, dy[8] = { 1, 0, -1, 0, 1, 1, -1, -1 }, visited[105][105];

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
	for (auto& i : rectangle) {
		int col1 = i[0], row1 = i[1], col2 = i[2], row2 = i[3];

		for (int r = row1 * 2; r <= row2 * 2; ++r) {
			for (int c = col1 * 2; c <= col2 * 2; ++c) {
				board[r][c] = 1;
			}
		}
	}

	vector<pair<int, int>> er;

	for (int i = 1; i <= 100; ++i) {
		for (int j = 1; j <= 100; ++j) {
			visited[i][j] = 1e9;
			if (board[i][j] == 0) continue;
			int cnt = 0;
			for (int k = 0; k < 8; ++k) {
				if (board[i + dx[k]][j + dy[k]] == 0) board[i][j] = 2;
			}
		}
	}

	queue<pair<int, int>> que;
	visited[characterY * 2][characterX * 2] = 0;
	que.push({ characterY * 2, characterX * 2});

	while (!que.empty()) {
		int curR = que.front().first, curC = que.front().second; que.pop();
		if (curR == itemY * 2 && curC == itemX * 2) {
			return visited[curR][curC] / 2;
		}

		for (int i = 0; i < 4; ++i) {
			int nxR = curR + dx[i], nxC = curC + dy[i];
			if (visited[nxR][nxC] != 1e9 || board[nxR][nxC] != 2) continue;
			visited[nxR][nxC] = visited[curR][curC] + 1;
			que.push({ nxR, nxC });
		}
	}
}

