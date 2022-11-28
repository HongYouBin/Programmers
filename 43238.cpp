//입국심사
//https://school.programmers.co.kr/learn/courses/30/lessons/43238

#include <string>
#include <vector>

#define ll long long
using namespace std;

bool check(vector<int>& times, int n, ll mid){
    ll cnt = 0;
    for(auto& t:times){
        cnt+=mid/t;
    }
    if(cnt>=n) return true;
    else return false;
}

long long solution(int n, vector<int> times) {
    ll answer;
    ll start = 0, end = 10000000000000;
    while(start<=end){
        ll mid = (start+end)/2;
        if(check(times, n, mid)){
            answer = mid;
            end = mid-1;
        }
        else start = mid+1;
    }
    return answer;
}