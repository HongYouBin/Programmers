#include <string>
#include <vector>
#include <iostream>
#define inf 1e9
using namespace std;

int dp[100001][2];
vector<int> ad[100001];

// 등대

int dfs(int node, int prevNode, bool mark) {
	if (dp[node][mark] != 0) return dp[node][mark];

	int& lightCnt = dp[node][mark];
	int noLight = 0, light = 1;
	if (mark) {
		for (auto& nxt : ad[node]) {
			if (nxt == prevNode) continue;
			noLight += dfs(nxt, node, 0);
		}
	}
	for (auto& nxt : ad[node]) {
		if (nxt == prevNode) continue;
		light += dfs(nxt, node, 1);
	}
	if (mark) {
		lightCnt = min(light, noLight);
	}
	else lightCnt = light;
	return lightCnt;
}

int solution(int n, vector<vector<int>> lighthouse) {
	for (auto& lh : lighthouse) {
		ad[lh[0]].emplace_back(lh[1]);
		ad[lh[1]].emplace_back(lh[0]);
	}
	fill(&dp[0][0], &dp[100000][1], 0);
	int ans = dfs(1, 0, 0);
	fill(&dp[0][0], &dp[100000][1], 0);
	ans = min(ans, dfs(1, 0, 1));
	return ans;
}

int main() {
	vector<vector<int>> vt;
	for (int i = 0; i < 7; ++i) {
		vector<int> inp;
		int a, b;
		cin >> a >> b;
		inp.push_back(a);
		inp.push_back(b);
		vt.emplace_back(inp);
	}
	solution(8, vt);
}
/*
1 2
1 3
1 4
1 5
5 6
5 7
5 8
*/