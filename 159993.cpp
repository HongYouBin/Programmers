// 159993
//미로 탈출
#include <string>
#include <vector>
#include <queue>

#define ll long long
#define inf 1e9
using namespace std;

int arr[101][101], dst1[101][101], dst2[101][101];
int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };

int solution(vector<string> maps) {
	int ans1 = 0, ans2 = 0;
	queue < pair<int, int>> q1, q2;
	int N = maps.size(), M = maps[0].size();

	for (int i = 0; i < maps.size(); ++i) {
		for (int j = 0; j < maps[i].size(); ++j) {
			if (maps[i][j] == 'S') {
				arr[i][j] = 1;
				q1.push({ i, j });
			}
			else if (maps[i][j] == 'L') {
				arr[i][j] = 2;
				q2.push({ i, j });
			}
			else if (maps[i][j] == 'E') arr[i][j] = 3;
			else if (maps[i][j] == 'X') arr[i][j] = -1;
			else arr[i][j] = 0;
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			dst1[i][j] = inf;
			dst2[i][j] = inf;
		}
	}

	dst1[q1.front().first][q1.front().second] = 0;
	while (!q1.empty()) {
		int curR = q1.front().first, curC = q1.front().second;
		q1.pop();
		if (arr[curR][curC] == 2) {
			ans1 = dst1[curR][curC];
			break;
		}

		for (int i = 0; i < 4; ++i) {
			int nxR = curR + dx[i], nxC = curC + dy[i];
			if (nxR < 0 || N <= nxR || nxC < 0 || M <= nxC) continue;
			if (arr[nxR][nxC] == -1 || dst1[nxR][nxC] <= dst1[curR][curC] + 1) continue;
			dst1[nxR][nxC] = dst1[curR][curC] + 1;
			q1.push({ nxR, nxC });
		}
	}

	dst2[q2.front().first][q2.front().second] = 0;
	while (!q2.empty()) {
		int curR = q2.front().first, curC = q2.front().second; q2.pop();
		if (arr[curR][curC] == 3) {
			ans2 = dst2[curR][curC];
			break;
		}

		for (int i = 0; i < 4; ++i) {
			int nxR = curR + dx[i], nxC = curC + dy[i];
			if (nxR < 0 || N <= nxR || nxC < 0 || M <= nxC) continue;
			if (arr[nxR][nxC] == -1 || dst2[nxR][nxC] <= dst2[curR][curC] + 1) continue;
			dst2[nxR][nxC] = dst2[curR][curC] + 1;
			q2.push({ nxR, nxC });
		}
	}
	if (ans1 == 0 || ans2 == 0) return -1;
	else return ans1 + ans2;
}