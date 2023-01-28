//154540
//무인도 여행
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int visited[101][101], numArr[101][101], dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
int rSize, cSize;

int bfs(int row, int col) {
	int sum = 0;
	queue<pair<int, int>> q;
	q.push({ row, col });
	sum += numArr[row][col];
	visited[row][col] = 1;

	while (!q.empty()) {
		int curR = q.front().first, curC = q.front().second; q.pop();

		for (int i = 0; i < 4; ++i) {
			int nxR = curR + dx[i], nxC = curC + dy[i];
			if (nxR < 0 || rSize <= nxR || nxC < 0 || cSize <= nxC) continue;
			if (visited[nxR][nxC]) continue;
			sum += numArr[nxR][nxC];
			q.push({ nxR, nxC });
			visited[nxR][nxC] = 1;
		}
	}
	return sum;
}

vector<int> solution(vector<string> maps) {
	vector<int> ans;
	rSize = maps.size();
	cSize = maps[0].size();

	for (int i = 0; i < rSize;++i) {
		string map = maps[i];
		for (int j = 0; j < cSize; ++j) {
			if (map[j] == 'X') {
				visited[i][j] = 1;
				numArr[i][j] = -1;
			}
			else {
				numArr[i][j] = map[j] - '0';
			}
		}
	}

	for (int i = 0; i < rSize; ++i) {
		for (int j = 0; j < cSize; ++j) {
			if (visited[i][j]) continue;
			ans.emplace_back(bfs(i, j));
		}
	}
	if (ans.empty()) ans.emplace_back(-1);
	sort(ans.begin(), ans.end());
	return ans;
}