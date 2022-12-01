//양궁대회
// https://school.programmers.co.kr/learn/courses/30/lessons/92342

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int totalSum = 0, lionArr[11], gap = 0;
vector<int> ans(11);

void check(int lionCnt, int n, vector<int>& info) {
    if (lionCnt > n) return;
    if (lionCnt < n) {
        lionArr[10] = n - lionCnt;
    }
    int lionSum = 0, aSum = 0;
    for (int i = 0; i < 11; ++i) {
        if (lionArr[i] == 0 && info[i] == 0) continue;
        if (lionArr[i] > info[i]) lionSum += 10 - i;
        else aSum += 10 - i;
    }
    if (lionSum <= aSum) return;
    if (lionSum - aSum > gap) {
        gap = lionSum - aSum;
        for (int i = 0; i < 11; ++i) ans[i] = lionArr[i];
    }
    else if (lionSum - aSum == gap) {
        for (int i = 10; 0 <= i; --i) {
            if (ans[i] > lionArr[i]) return;
            else if (ans[i] < lionArr[i]) {
                for (int i = 0; i < 11; ++i) ans[i] = lionArr[i];
                return;
            }
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    for (int num = 1; num <= n; ++num) {
        vector<int> bin(info.size());
        fill(bin.end() - num, bin.end(), 1);
        do {
            int lionCnt = 0;
            for (int i = 0; i < 11; ++i) lionArr[i] = 0;
            for (int i = 0; i < info.size(); ++i) {
                if (bin[i] == 0) continue;
                lionCnt += info[i] + 1;
                lionArr[i] = info[i] + 1;
            }
            check(lionCnt, n, info);
        } while (next_permutation(bin.begin(), bin.end()));
    }
    int sum = 0;
    for (int i = 0; i < 11; ++i) {
        sum += ans[i];
    }
    if (sum == 0) {
        vector<int> vt;
        vt.emplace_back(-1);
        return vt;
    }
    else return ans;
}
