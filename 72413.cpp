//합승 택시 요금
//https://school.programmers.co.kr/learn/courses/30/lessons/72413
#include <string>
#include <vector>

#define inf 20000001
using namespace std;

int arr[202][202];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int ans = inf;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i==j) arr[i][j] = 0;
            else arr[i][j] = inf;
        }
    }
    
    for(auto& f:fares){
        arr[f[0]][f[1]] = f[2];
        arr[f[1]][f[0]] = f[2];
    }
    
   for(int k=1;k<=n;++k){
       for(int i=1;i<=n;++i){
           for(int j=1;j<=n;++j){
               arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
           }
       }
   }
    
    for(int i=1;i<=n;++i){
        ans = min(ans, arr[s][i]+arr[i][a]+arr[i][b]);
    }
    return ans;
}