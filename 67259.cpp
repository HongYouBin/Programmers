// 경주로 건설
// https://school.programmers.co.kr/learn/courses/30/lessons/67259
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define inf 1e9
using namespace std;

class Pos {
public:
	int row, col, dir;
};

struct comp {
	bool operator()(pair<int, Pos>& a, pair<int, Pos>& b) {
		return a.first < b.first;
	}
};

int arr[26][26][4], dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
priority_queue<pair<int, Pos>,vector<pair<int, Pos>>, comp> pq;

void init() {
	for (int i = 0; i < 25; ++i) {
		for (int j = 0; j < 25; ++j) {
			for (int t = 0; t < 4; ++t) {
				arr[i][j][t] = inf;
			}
		}
	}

	Pos inp;
	inp.row = 0; inp.col = 0; inp.dir = 0;
	//arr[inp.row][inp.col][inp.dir] = 0;
	pq.push({ 0, inp });
	inp.dir = 1;
	//arr[inp.row][inp.col][inp.dir] = 0;
	pq.push({ 0, inp });
}

void setNxt(int r, int c, int dir, int dst, vector<vector<int>>& board) {
	int rSize = board.size(), cSize = board[0].size();
	Pos inp;

	int nxR = r + dx[dir], nxC = c + dy[dir];
	if (!(nxR < 0 || rSize <= nxR || nxC < 0 || cSize <= nxC || board[nxR][nxC] || arr[nxR][nxC][dir]<=dst+100)) {
		inp.row = nxR;
		inp.col = nxC;
		inp.dir = dir;
		pq.push({ -dst - 100, inp });
	}
	int nxDir = dir - 1;
	if (nxDir == -1) nxDir = 3;
	nxR = r + dx[nxDir], nxC = c + dy[nxDir];
	if (!(nxR < 0 || rSize <= nxR || nxC < 0 || cSize <= nxC || board[nxR][nxC] || arr[nxR][nxC][dir] <= dst + 600)) {
		inp.row = nxR;
		inp.col = nxC;
		inp.dir = nxDir;
		pq.push({ -dst - 600, inp });
	}

	nxDir = dir + 1;
	if (nxDir == 4) nxDir = 0;
	nxR = r + dx[nxDir], nxC = c + dy[nxDir];
	if (!(nxR < 0 || rSize <= nxR || nxC < 0 || cSize <= nxC || board[nxR][nxC] || arr[nxR][nxC][dir] <= dst + 600)) {
		inp.row = nxR;
		inp.col = nxC;
		inp.dir = nxDir;
		pq.push({ -dst - 600, inp });
	}
}

int solution(vector<vector<int>> board) {
	init();

	while (!pq.empty()) {
		int curR = pq.top().second.row, curC = pq.top().second.col, curD = pq.top().second.dir, dst = -pq.top().first;
		pq.pop();
		if (dst >= arr[curR][curC][curD]) continue;
		arr[curR][curC][curD] = dst;
		setNxt(curR, curC, curD, dst, board);
	}
	int minNum = inf;
	for (int i = 0; i < 4; ++i) {
		minNum = min(minNum, arr[board.size() - 1][board[0].size() - 1][i]);
	}
	return minNum;
}
