//뒤에 있는 큰 수 찾기
//154539

#include <string>
#include <vector>
#include <queue>

#define pii pair<int,int>
#define ll long long
using namespace std;

struct comp{
    bool operator()(pii a, pii b){
        return a.first >= b.first;
    }
};

priority_queue<pii, vector<pii>, comp> pq;

vector<int> solution(vector<int> numbers) {
    vector<int> ans(numbers.size());
    fill(ans.begin(), ans.end(), -1);
    
    for(int i = 0; i < numbers.size(); ++i){
        int n = numbers[i];
        if(!pq.empty()){
            while(!pq.empty() && n>pq.top().first){
                ans[pq.top().second] = n;
                pq.pop();
            }
        }
        pq.push({n, i});
    }
    return ans;
}