//교점에 별 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/87377
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define pii pair<ll, ll>
#define inf 10000000001
#define ll long long
using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> ans;
    vector<pii> vt;
    pii inp;
    ll minX = inf, maxX = -inf, minY = inf, maxY = -inf;
    for (int i = 0; i < line.size(); ++i) {
        for (int j = i + 1; j < line.size(); ++j) {
            ll A = line[i][0], B = line[i][1], E = line[i][2], C = line[j][0], D = line[j][1], F = line[j][2];
            if (!(A * D - B * C)) continue;
            ll x = (B * F - E * D) / (A * D - B * C), y = (E * C - A * F) / (A * D - B * C);
            if((B * F - E * D) % (A * D - B * C)) continue;
            if((E * C - A * F) % (A * D - B * C)) continue;
            inp = { x, y };
            vt.emplace_back(inp);
            minX = min(minX, x); maxX = max(maxX, x); minY = min(minY, y); maxY = max(maxY, y);
        }
    }
    vector<vector<ll>> arr(maxY-minY+1, vector<ll>(maxX-minX+1));
    for (ll i = 0; i < arr.size(); ++i) {
        for (ll j = 0; j < arr[0].size(); ++j) {
            arr[i][j] = 0;
        }
    }
    for (auto& xy : vt) {
        ll nX = xy.first, nY = xy.second;
        arr[maxY - nY][nX - minX] = 1;
    }
    for (ll i = 0; i < arr.size(); ++i) {
        string s;
        for (ll j = 0; j < arr[0].size(); ++j) {
            if (arr[i][j] == 0) s += ".";
            else s += "*";
        }
        ans.emplace_back(s);
    }
    return ans;
}
