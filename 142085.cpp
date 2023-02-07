#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> pq;

int solution(int n, int k, vector<int> enemy) {
    
    int sum = 0;
    for (int i = 0; i < enemy.size();++i) {
       
        int e = enemy[i];
        if (pq.size() < k) pq.push(-e);
        else if (-pq.top() <= e) {
            sum -= pq.top();
            pq.pop();
            pq.push(-e);
        }
        else sum += e;
        
         if (sum > n) {
            return i;
        }
    }
    return enemy.size();
}
