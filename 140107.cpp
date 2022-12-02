// 점 찍기
// https://school.programmers.co.kr/learn/courses/30/lessons/140107

#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#define ll long long
using namespace std;

long long solution(int k, int d) {
    ll ans = 0;
    ll lk = (ll) k;
    ll ld = (ll) d;
    for(ll r = 0;r*k<=d;++r){
        ll maxN = (ll)sqrt(((ld*ld)-(r*lk*r*lk))/(lk*lk));
        ans+=maxN+1;
    }
    return ans;
}