// 42890
// 후보키

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

vector<int> candid;
int ans;

void check(int bit) {
    for (int i = 0; i < candid.size(); ++i) {
        if ((bit & candid[i]) == candid[i]) return;
    }
    candid.emplace_back(bit);
    ans++;
}

int solution(vector<vector<string>> relation) {

    int idxNum = relation[0].size();
    for (int i = 1; i <= idxNum; ++i) {
        vector<int> bin(idxNum);
        fill(bin.end() - i, bin.end(), 1);
        do {
            bool flag = true;
            map<string, int> mp;
            for (int j = 0; j < relation.size(); ++j) {
                string tmp = "";
                for (int t = 0; t < relation[j].size(); ++t) {
                    if (bin[t] == 0) continue;
                    tmp += relation[j][t];
                }
                if (mp.find(tmp) != mp.end()) {
                    flag = false;
                    break;
                }
                else mp[tmp] = 1;
            }
            if (flag) {
                int bit = 0;
                for (int j = 0; j < idxNum; ++j) {
                    if (bin[j] == 0) continue;
                    bit = (bit | 1 << j);
                }
                check(bit);
            }
        } while (next_permutation(bin.begin(), bin.end()));
    }
    return ans;
}
