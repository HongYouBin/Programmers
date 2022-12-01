//k진수에서 소수 개수 구하기
//92335

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool check(long long num){
    if(num<=1) return false;
    for(long long i=2;i*i<=num + 1;++i){
        if(num%i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int ans = 0;
    string kNum;
    while(true){
        if(n==0) break;
        kNum+=(n%k)+'0'; //to_string
        n/=k;
    }
    reverse(kNum.begin(), kNum.end());
    long long inp = 0;
    vector<long long> vt;
    for(int i=0;i<kNum.size();++i){
        if(kNum[i]!='0'){
            inp*=10;
            inp+=kNum[i]-'0';
        }
        else{
            if(check(inp)) ans++;
            inp = 0;
        }
    }    
    if(check(inp)) ans++;
    
    return ans;
}