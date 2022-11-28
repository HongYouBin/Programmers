#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer(right - left + 1);
    
    for(long long i=left;i<= right; ++ i){
        int N = i/n + 1;
        int M = i%n + 1;
        
        if(M<N) answer[i-left] = N;
        else answer[i-left] = M;
    }
    
    return answer;
}