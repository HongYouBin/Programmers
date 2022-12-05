// 스타수열
//https://school.programmers.co.kr/learn/courses/30/lessons/70130

#include <string>
#include <vector>
#include <map>
using namespace std;

map<int, int> mp;

int solution(vector<int> a) {
    if(a.size()==1) return 0;
    int ans = 0;
    for(auto& i:a){
        mp[i]++;
    }
    
    for(auto it=mp.begin();it!=mp.end();++it){
        if(it->second<=ans) continue;
        int common = it->first;
        int cnt = 0;
        for(int i=0;i<a.size()-1;++i){
            if(a[i]==a[i+1]) continue;
            if(a[i]==common||a[i+1]==common) {
                cnt++;
                i++;
            }
        }
        ans = max(ans, cnt);
    }
    return ans*2;
}