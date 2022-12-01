// 풍선 터트리기
// https://school.programmers.co.kr/learn/courses/30/lessons/68646

#include <string>
#include <vector>
#include <algorithm>
#define inf 1e9+1
using namespace std;

int solution(vector<int> a) {
    int ans = 1;
    if(a.size()>=1) ans++;
    vector<int> fromR(a.size());
    vector<int> fromL(a.size());
    int minNum = inf;
    for(int i=0;i<a.size();++i){
        minNum = min(a[i], minNum);
        fromR[i] = minNum;
    }
    minNum = inf;
    for(int i=a.size()-1;0<=i;--i){
        minNum = min(a[i], minNum);
        fromL[i] = minNum;
    }
    for(int i=1;i<a.size()-1;++i){
        if(a[i]<fromR[i-1] || a[i]<fromL[i+1]) ans++;
    }
    return ans;
}