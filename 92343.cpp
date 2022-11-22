#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> edge[20];
int visited[(1 << 17)], ans;

void solv(int num, vector<int>& info) {
	if (visited[num]) return;
	visited[num] = 1;

	int sheep = 0, wolf = 0;
	for (int i = 0; i < info.size(); ++i) {
		if (!(num&(1 << i))) continue;
		if (info[i]) wolf++;
		else sheep++;
	}
	if (sheep == wolf) return;
	ans = max(sheep, ans);

	for (int i = 0; i < info.size(); ++i) {
		if (!(num&(1 << i))) continue;
		for (int& j : edge[i]) {
			solv((num | (1 << j)), info);
		}
	}
}

int solution(vector<int> info, vector<vector<int>> edges) {
	for (auto& ed : edges) {
		edge[ed[0]].emplace_back(ed[1]);
		edge[ed[1]].emplace_back(ed[0]);
	}
	solv(1, info);
	return ans;
}