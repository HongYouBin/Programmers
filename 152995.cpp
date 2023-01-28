//152995
//인사고과

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100001];
int notUse[100001];

int solution(vector<vector<int>> scores) {
    int ans = 0;
    int wSum = scores[0][0] + scores[0][1];
    for(auto score : scores){
        arr[score[0]] = max(arr[score[0]], score[1]);
    }

    for(int i=0;i<scores.size();++i){
        auto score = scores[i];
        for(int s=score[0] + 1;s<=100000;++s){
            if(arr[s] > score[1]){
                notUse[i] = 1;
                break;
            }
        }
    }

    if(notUse[0]) return -1;
    for(int i=1;i<scores.size();++i){
        if(notUse[i]) continue;
       auto score = scores[i];
       int sum = score[0] + score[1];
       if(sum>wSum) ans++;
    }
    return ans+1;
}