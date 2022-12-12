// 불량 사용자
// https://school.programmers.co.kr/learn/courses/30/lessons/64064

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


bool check(vector<string>& user, vector<string>& banned) {
	map<string, int> mp;
	for (auto& u : user) {
		for (int i = 1; i <= u.size(); ++i) {
			vector<int> bin(u.size());
			fill(bin.end() - i, bin.end(), 1);
			fill(bin.begin(), bin.end() - i, 0);
			do {
				string newS = u;
				for (int j = 0; j < u.size(); ++j) {
					if (bin[j] == 0) continue;
					newS[j] = '*';
				}
				mp[newS]++;
			} while (next_permutation(bin.begin(), bin.end()));
		}
	}

	for (auto& b : banned) {
		if (mp[b] < 1) return false;
		mp[b]--;
	}
	return true;
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
