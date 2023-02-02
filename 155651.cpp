//155651
//호텔 대실

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> vt;
    pair<int, int> inp;
    for (int i = 0; i < book_time.size(); ++i) {
        int fi = stoi(book_time[i][0].substr(0, 2)) * 60 + stoi(book_time[i][0].substr(3, 2));
        int sec = stoi(book_time[i][1].substr(0, 2)) * 60 + stoi(book_time[i][1].substr(3, 2));
        vt.push_back({ fi, sec });
    }
    sort(vt.begin(), vt.end());

    int ans = 1;

    pq.push(vt[0].second + 10);
    for (int i = 1; i < vt.size(); ++i) {
        while (!pq.empty() && pq.top() <= vt[i].first) pq.pop();
        pq.push(vt[i].second + 10);
        ans = max(ans, (int)pq.size());
    }
    return ans;
}
