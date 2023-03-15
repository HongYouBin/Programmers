#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

map<string, vector<int>> mp;

void fillMap(vector<string>& sVt, int score) {
    for (int bit = 0; bit < (1 << sVt.size()); ++bit) {
        string input = "";
        for (int i = 0; i < sVt.size(); ++i) {
            if ((bit & (1 << i)) == 0) input += '-';
            else input += sVt[i];
        }
        mp[input].emplace_back(score);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> ans;
    for (auto& s : info) {
        stringstream ss(s);
        string input = "";
        vector<string> sVt(4);
        
        for (int i = 0; i < 4; ++i) {
            ss >> input;
            sVt[i] = input;
        }
        ss >> input;
        int score = stoi(input);
        fillMap(sVt, score);
    }

    for (auto it = mp.begin(); it != mp.end(); ++it) sort(it->second.begin(), it->second.end());
    
    for (auto& s : query) {
        stringstream ss(s);
        string input;
        string searchStr = "";
        for (int i = 0; i < 7; ++i) {
            ss >> input;
            if (input == "and") continue;
            searchStr += input;
        }
        ss >> input;
        int score = stoi(input);
        int idx = lower_bound(mp[searchStr].begin(), mp[searchStr].end(), score) - mp[searchStr].begin();
        ans.push_back(mp[searchStr].size() - idx - 1);
    }
    return ans;
}

int main() {
    solution({ "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" }, { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" });
}