//72411
//메뉴 리뉴얼

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> mp;

class SetMenu {
public:
	string name;
	int cnt;
};

bool cmp(SetMenu a, SetMenu b) {
	return a.cnt > b.cnt;
}

void solv(int level, vector<int>& visited, string& order) {
	if (level == order.length()) {
		int cnt = 0;
		string tmp = "";
		vector<char> cVt;
		for (int i = 0; i < order.length(); ++i) {
			if (visited[i] == false) continue;
			cnt++;
			cVt.emplace_back(order[i]);
		}
		if (cnt < 2) return;
		sort(cVt.begin(), cVt.end());
		for (auto& c : cVt) tmp += c;
		mp[tmp]++;
		return;
	}

	visited[level] = true;
	solv(level + 1, visited, order);
	visited[level] = false;
	solv(level + 1, visited, order);
}

vector<string> solution(vector<string> orders, vector<int> course) {
	
	for (auto& order : orders) {
		vector<int> visited(order.size());
		solv(0, visited, order);
	}

	vector<string> ans;
	vector<SetMenu> vt[11];

	SetMenu sm;
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		if (it->second < 2) continue;
		sm.cnt = it->second;
		sm.name = it->first;
		vt[sm.name.length()].emplace_back(sm);
	}

	for (int i = 1; i <= 10; ++i) sort(vt[i].begin(), vt[i].end(), cmp);
	for (auto& c : course) {
		if (vt[c].empty()) continue;
		ans.emplace_back(vt[c][0].name);
		for (int i = 1; i < vt[c].size(); ++i) {
			if (vt[c][0].cnt == vt[c][i].cnt) ans.emplace_back(vt[c][i].name);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

int main() {
	solution({ "XYZ", "XWY", "WXA" }, { 2, 3, 4 });
}