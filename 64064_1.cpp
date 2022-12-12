// 불량 사용자
// https://school.programmers.co.kr/learn/courses/30/lessons/64064

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool check(vector<string>& user, vector<string>& banned) {
	fill(visited, visited + 10, 0);
	int cnt = 0;

	for (int i = 0; i < banned.size(); ++i) {
		for (int j = 0; j < user.size(); ++j) {
			if (visited[j]) continue;
			if (banned[i].size() != user[j].size()) continue;
			bool flag = true;
			for (int t = 0; t < user[i].size(); ++t) {
				if (banned[i][t] == '*') continue;
				else if (user[j][t] != banned[i][t]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				visited[j] = 1;
				cnt++;
				break;
			}
		}
	}
	if (cnt == banned.size()) return true;
	else return false;
}

int solution(vector<string> user_id, vector<string> banned_id) {
	int ans = 0;
	vector<int> bins(user_id.size());
	fill(bins.end() - banned_id.size(), bins.end(), 1);
	fill(bins.begin(), bins.end() - banned_id.size(), 0);
	do {
		vector<string> user;
		for (int t = 0; t < user_id.size(); ++t) {
			if (bins[t] == 0) continue;
			user.emplace_back(user_id[t]);
		}
		if (check(user, banned_id)) ans++;
	} while (next_permutation(bins.begin(), bins.end()));

	return ans;
}