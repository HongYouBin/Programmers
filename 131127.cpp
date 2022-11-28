#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> wantMap, mp;

bool check(){
    for(auto it = wantMap.begin(); it!=wantMap.end(); ++it){
        string wantName = it->first;
        int wantCnt = it->second;
        if(mp[wantName]<wantCnt) return false;
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int ans = 0;
    for(int i=0;i<want.size();++i){
        wantMap[want[i]] =  number[i];
    }
    
    for(int i=0;i<10;++i){
        mp[discount[i]]++;
    }
    if(check()) ans++;
    for(int i=10;i<discount.size();++i){
        mp[discount[i-10]]--;
        mp[discount[i]]++;
        if(check()) ans++;
    }
    return ans;
}