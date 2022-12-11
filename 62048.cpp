// 멀쩡한 사각형
// https://school.programmers.co.kr/learn/courses/30/lessons/62048
#include <iostream>
#include <algorithm>

#define ll long long
using namespace std;

ll solv(ll a, ll b){
    ll maxN = max(a, b);
    ll minN = min(a, b);
    if(minN!=0) return solv(maxN%minN, minN);
    else return maxN;
}

long long solution(int w,int h) {
    ll lW = (ll) w;
    ll lH = (ll) h;
    ll ans = lW*lH;
    
    return ans-(lW+lH - solv(lW, lH));
}