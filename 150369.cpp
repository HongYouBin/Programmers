//택배 배달과 수거
//150369 kakao 기출

#include <string>
#include <vector>
#include <iostream>
#include <stack>

#define ll long long
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long ans = 0;
    ll dSum = 0, pSum = 0;
    stack<int> dSt, pSt;

    for (int i = 0; i < pickups.size(); ++i) {
        dSt.push(deliveries[i]);
        pSt.push(pickups[i]);
    }

    while (!dSt.empty() && dSt.top() == 0) dSt.pop();
    while (!pSt.empty() && pSt.top() == 0) pSt.pop();

    while (!(dSt.empty() && pSt.empty())) {
        ans += max(dSt.size(), pSt.size()) * 2;

        while (!dSt.empty()) {
            if (dSt.top() == 0) dSt.pop();
            else if (dSt.top() + dSum <= cap) {
                dSum += dSt.top();
                dSt.pop();
            }
            else {
                dSt.top() -= (cap - dSum);
                dSum = 0;
                break;
            }
        }

        while (!pSt.empty()) {
            if (pSt.top() == 0) pSt.pop();
            else if (pSt.top() + pSum <= cap) {
                pSum += pSt.top();
                pSt.pop();
            }
            else {
                pSt.top() -= (cap - pSum);
                pSum = 0;
                break;
            }
        }
    }
    return ans;
}