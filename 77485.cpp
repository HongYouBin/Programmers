// 행렬 테두리 회전
// https://school.programmers.co.kr/learn/courses/30/lessons/77485
#include <string>
#include <vector>

using namespace std;

int arr[101][101], newArr[101][101];

int solv(int row1, int col1, int row2, int col2) {
	int minNum = 1e9;
	for (int i = 1; i <= 100; ++i) {
		for (int j = 1; j <= 100; ++j) {
			newArr[i][j] = 0;
		}
	}

	for (int c = col1; c <= col2; ++c) {
		minNum = min(minNum, arr[row1][c]);
		if (c == col2) newArr[row1 + 1][col2] = arr[row1][c];
		else newArr[row1][c + 1] = arr[row1][c];
	}
	for (int r = row1; r <= row2; ++r) {
		minNum = min(minNum, arr[r][col2]);
		if (r == row2) newArr[row2][col2 - 1] = arr[row2][col2];
		else newArr[r + 1][col2] = arr[r][col2];
	}
	for (int c = col2; col1 <= c; --c) {
		minNum = min(minNum, arr[row2][c]);
		if (c == col1) newArr[row2 - 1][col1] = arr[row2][c];
		else newArr[row2][c - 1] = arr[row2][c];
	}
	for (int r = row2; row1 <= r; --r) {
		minNum = min(minNum, arr[r][col1]);
		if (r == row1) newArr[row1][col1 + 1] = arr[row1][col1];
		else newArr[r - 1][col1] = arr[r][col1];
	}

	for (int i = 1; i <= 100; ++i) {
		for (int j = 1; j <= 100; ++j) {
			if (newArr[i][j] == 0) continue;
			arr[i][j] = newArr[i][j];
		}
	}
	return minNum;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int> ans;
	int num = 1;
	for (int i = 1; i <= rows; ++i) {
		for (int j = 1; j <= columns; ++j) {
			arr[i][j] = num;
			num++;
		}
	}

	for (auto& q : queries) {
		ans.push_back(solv(q[0], q[1], q[2], q[3]));
	}
	return ans;
}