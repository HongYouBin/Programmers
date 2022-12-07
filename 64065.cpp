// 65065
// https://school.programmers.co.kr/learn/courses/30/lessons/64065

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

bool used[100001];

vector<int> solution(string s) {
    vector<int> ans;
    vector<vector<int>> vt;
    for (int i = 1; i < s.size() - 1; ++i) {
        int num = 0;
        if (s[i] == '{') {
            i++;
            vector<int> numVt;
            while (true) {
                if (s[i] == ',') {
                    numVt.emplace_back(num);
                    num = 0;
                    i++;
                }
                else if (s[i] == '}') {
                    numVt.emplace_back(num);
                    break;
                }
                num *= 10;
                num += s[i] - '0';
                i++;
            }
            vt.emplace_back(numVt);
        }
    }
    sort(vt.begin(), vt.end(), cmp);
    for (auto& numbers : vt) {
        for (auto& number : numbers) {
            if (used[number]) continue;
            ans.emplace_back(number);
            used[number] = 1;
        }
    }
    return ans;
}
