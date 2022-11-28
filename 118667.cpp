//118667
//두 큐 합 같게 만들기(카카오 기출)
//https://school.programmers.co.kr/learn/courses/30/lessons/118667

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long sum1 = 0, sum2 = 0;
    for(int i=0;i<queue1.size();++i){
        sum1+=queue1[i];
    }
    for(int i=0;i<queue2.size();++i){
        sum2+=queue2[i];
    }
    long num = (sum1+sum2)/2;
    long ans = 0, idx1 = 0, idx2 = 0;
    long old1 = sum1, old2 = sum2;
    while(true){
        if(sum1==num && sum2==num) return ans;
        else if(ans>queue1.size() - idx1 +queue2.size() - idx2 + 1) return -1;
        
        else if(sum1>num){
            sum1-=queue1[idx1];
            sum2+=queue1[idx1];
            queue2.emplace_back(queue1[idx1]);
            idx1++;
            ans++;
        }
        else {
            sum2-=queue2[idx2];
            sum1+=queue2[idx2];
            queue1.emplace_back(queue2[idx2]);
            idx2++;
            ans++;
        }
    }
}