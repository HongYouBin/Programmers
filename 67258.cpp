// 67258
//https://school.programmers.co.kr/learn/courses/30/lessons/67258

#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> mp;

vector<int> solution(vector<string> gems) {
	vector<int> ans;
	int cnt = 0, start = 0, newCnt = 0, minS = 1e9, ansL, ansR;
	for (auto& g : gems) {
		mp[g]++;
		if (mp[g] == 1) cnt++;
	}
	mp.clear();

	for (int i = 0; i < gems.size(); ++i) {
		mp[gems[i]]++;
		if (mp[gems[i]] == 1) newCnt++;
		if (newCnt == cnt) {
			while (true) {
				if (mp[gems[start]] - 1 == 0) break;
				mp[gems[start]]--;
				start++;
			}
			if (i - start + 1 < minS) {
                minS = i-start+1;
				ansL = start;
				ansR = i;
			}
			mp[gems[start]]--;
			start++;
            newCnt--;
		}
	}
	ans.emplace_back(ansL + 1);
	ans.emplace_back(ansR + 1);
	return ans;
}