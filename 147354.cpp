#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int sCol;

bool comp(vector<int> a, vector<int> b) {
	if (a[sCol - 1] != b[sCol - 1]) return a[sCol - 1] < b[sCol - 1];
	else return a[0] > b[0];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
	sCol = col;

	sort(data.begin(), data.end(), comp);

	int bit = 0;

	for (int i = 0; i < data[row_begin - 1].size(); ++i) {
		bit += (data[row_begin - 1][i] % row_begin);
	}
	for (int i = row_begin; i < row_end; ++i) {
		int sum = 0;
		for (int j = 0; j < data[i].size(); ++j) {
			sum += (data[i][j] % (i + 1));
		}
		bit ^= sum;
	}
	return bit;
}

