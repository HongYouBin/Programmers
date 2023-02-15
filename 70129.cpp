#include <string>
#include <vector>

using namespace std;

int cnt, loop;

string makeBinary(int num, string s) {
	if (num == 0) return s;

	char newS = (num % 2) + '0';
	return makeBinary(num / 2, newS + s);
}

vector<int> solution(string s) {
	vector<int> ans;
	while (true) {
		loop++;
		int lth = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '0') cnt++;
			else lth++;
		}
		s = makeBinary(lth, "");
		if (s == "1") break;
	}
	ans.emplace_back(loop);
	ans.emplace_back(cnt);
	return ans;
}

int main() {
	solution("110010101001");
}