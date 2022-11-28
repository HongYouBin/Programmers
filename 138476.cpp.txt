//귤 고르기 138476
//https://school.programmers.co.kr/learn/courses/30/lessons/138476

#include <string>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

int arr[10000001];
vector<pii> vt;

int solution(int k, vector<int> tangerine) {
    int ans = 0;
    for(auto& tl:tangerine){
        arr[tl]++;
    }
    pii inp;
    for(int i=1;i<=10000000;++i){
        if(arr[i]==0) continue;
        inp = {-arr[i], i};
        vt.emplace_back(inp);
    }
    sort(vt.begin(), vt.end());
    for(auto& n:vt){
        if(k<=0) return ans;
        k+=n.first;
        ans++;
    }
}