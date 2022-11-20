#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <iostream>

#define pii pair<int, int>
#define pip pair<int, pair<int, int>>
using namespace std;

int areaNum[301][301], N, dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
int parent[1000001];

int findParent(int a) {
	if (parent[a] != a) {
		return parent[a] = findParent(parent[a]);
	}
	else return a;
}

void mergeParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a == b) return;
	if (a > b) parent[a] = b;
	else parent[b] = a;
}

void bfs(int row, int col, int height, int num, vector<vector<int>>& land) {
	queue<pii> q;

	areaNum[row][col] = num;
	q.push({ row, col });

	while (!q.empty()) {
		pii pos = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nxtR = pos.first + dx[i];
			int nxtC = pos.second + dy[i];
			if (nxtR < 0 || N <= nxtR || nxtC < 0 || N <= nxtC || areaNum[nxtR][nxtC]) continue;
			if (abs(land[pos.first][pos.second] - land[nxtR][nxtC]) > height) continue;
			areaNum[nxtR][nxtC] = num;
			q.push({ nxtR, nxtC });
		}
	}
}

int solution(vector<vector<int>> land, int height) {
	int ans = 0;
	N = land.size();

	int num = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (areaNum[i][j]) continue;
			num++;
			bfs(i, j, height, num, land);
		}
	}

	vector<pip> dist;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			for (int i = 0; i < 4; ++i) {
				int nxtR = r + dx[i];
				int nxtC = c + dy[i];
				if (nxtR < 0 || N <= nxtR || nxtC < 0 || N <= nxtC) continue;
				if (areaNum[r][c] == areaNum[nxtR][nxtC]) continue;
				pip inp = { abs(land[r][c] - land[nxtR][nxtC]), {areaNum[r][c], areaNum[nxtR][nxtC]} };
				dist.emplace_back(inp);
			}
		}
	}

	sort(dist.begin(), dist.end());
	for (int i = 1; i <= num; ++i) parent[i] = i;
	for (auto& i : dist) {
		int cst = i.first;
		int area1 = i.second.first;
		int area2 = i.second.second;
		if (findParent(area1) == findParent(area2)) continue;
		mergeParent(area1, area2);
		ans += cst;
	}
	return ans;
}
