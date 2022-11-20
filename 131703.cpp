#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool check(vector<vector<int>>& map, vector<vector<int>>& target) {
	for (int i = 0; i < map.size(); ++i) {
		for (int j = 0; j < map[0].size(); ++j) {
			if (map[i][j] != target[i][j]) return false;
		}
	}
	return true;
}

void init(vector<vector<int>>& beginning, vector<vector<int>>& map) {
	for (int i = 0; i < map.size(); ++i) {
		for (int j = 0; j < map[0].size(); ++j) {
			map[i][j] = beginning[i][j];
		}
	}
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
	int rowS = beginning.size(), colS = beginning[0].size();
	vector<vector<int>> map(rowS, vector<int>(colS));

	int ans = 0;
	for (ans = 0; ans <= rowS + colS; ++ans) {
		if (ans == rowS + colS) return -1;
		vector<int> bin(rowS + colS);
		fill(bin.end() - ans, bin.end(), 1);
		init(beginning, map);
		do {
			init(beginning, map);
			vector<int> changeR, changeC;
			for (int num = 0; num < rowS + colS; ++num) {
				if (bin[num] == 0) continue;
				if (num < rowS) changeR.emplace_back(num);
				else changeC.emplace_back(num - rowS);
			}
			for (auto& r : changeR) {
				for (int col = 0; col < colS; ++col) map[r][col] = !map[r][col];
			}
			for (auto& c : changeC) {
				for (int row = 0; row < rowS; ++row) map[row][c] = !map[row][c];
			}
			if (check(map, target)) return ans;
		} while (next_permutation(bin.begin(), bin.end()));
	}
}

int main() {
	vector<vector<int>> b;
	vector<vector<int>> t;

	for (int i = 0; i < 5; ++i) {
		vector<int> inp;
		int t;
		for (int j = 0; j < 5; ++j) {
			cin >> t;
			inp.emplace_back(t);
		}
		b.emplace_back(inp);
	}
	for (int i = 0; i < 5; ++i) {
		vector<int> inp;
		int ti;
		for (int j = 0; j < 5; ++j) {
			cin >> ti;
			inp.emplace_back(ti);
		}
		t.emplace_back(inp);
	}
	solution(b, t);
}
/*
0 1 0 0 0
1 0 1 0 1
0 1 1 1 0
1 0 1 1 0
0 1 0 1 0

0 0 0 1 1
0 0 0 0 1
0 0 1 0 1
0 0 0 1 0 
0 0 0 0 1
*/