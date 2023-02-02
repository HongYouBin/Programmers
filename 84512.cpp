//84512
//모음사전
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> vt;
map<string, int> mp;

int order = 1;
string sArr[5] = { "A", "E", "I", "O", "U" };

void solv(string s, int level, int cnt) {
	if (level == cnt) {
		mp[s] = 1;
		return;
	}

	for (int i = 0; i < 5; ++i) {
		string newS = s + sArr[i];
		solv(newS, level + 1, cnt);
	}
}

int solution(string word) {
	int ans = 0;
	for (int i = 1; i <= 5; ++i) {
		string s = "";
		solv(s, 0, i);
	}
	for (auto i = mp.begin(); i != mp.end(); ++i) {
		i->second = order++;
	}
	return mp[word];
}
