// 우박수열 정적분
// https://school.programmers.co.kr/learn/courses/30/lessons/134239

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> ans;
    vector<double> vt;

    int prevNum = k;
    bool flag = true;
    double n = 0;
    while (flag) {
        int nxtNum;
        if (prevNum % 2) nxtNum = prevNum * 3 + 1;
        else nxtNum = prevNum / 2;
        if (nxtNum == 1) flag = false;
        n += (double)(max(nxtNum, prevNum) - min(nxtNum, prevNum)) / 2;
        n += min(nxtNum, prevNum);
        vt.emplace_back(n);
        prevNum = nxtNum;
    }
    for (auto& range : ranges) {
        int start = 0 + range[0] - 1, end = vt.size() - 1 + range[1];
        double sum = 0;
        if (start > end) ans.emplace_back(-1);
        else ans.emplace_back(vt[end] - vt[start]);
    }
    return ans;
}