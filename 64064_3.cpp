// 불량 사용자
// https://school.programmers.co.kr/learn/courses/30/lessons/64064

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int visited[10];
map<int, int> mp;

void dfs(vector<string>& user, vector<string>& bann, int level, int num) {
	if (level >= bann.size()) {
		//ans++;
		mp[num]++;
		return;
	}

	string curS = bann[level];

	for (int i = 0; i < user.size(); ++i) {
		if (visited[i]) continue;
		string curU = user[i];
		bool flag = true;
		if (curS.size() != curU.size()) continue;
		for (int j = 0; j < curU.size(); ++j) {
			if (curS[j] == '*') continue;
			else if (curS[j] != curU[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			visited[i] = 1;
			dfs(user, bann, level + 1, (num|(1<<i)));
			visited[i] = 0;
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	dfs(user_id, banned_id, 0, 0);
	int ans = mp.size();
	return ans;
}