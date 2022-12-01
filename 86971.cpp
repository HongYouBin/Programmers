//전력망을 둘로 나누기 
// https://school.programmers.co.kr/learn/courses/30/lessons/86971

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> arr[101];
int visited[101];

int dfs(int node, int div1, int div2){
    queue<int> q;
    q.push(node);
    int cnt = 0;

    while(!q.empty()){
        int curN = q.front(); q.pop();
        if(visited[curN]) continue;
        visited[curN] = 1;
        cnt++;
        for(auto& nxN:arr[curN]){
            if(visited[nxN]) continue;
            if((curN==div1&&nxN==div2)||(curN==div2&&nxN==div1)) continue;
            q.push(nxN);
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int ans = 1e9;
    for(auto& wire:wires){
        arr[wire[0]].emplace_back(wire[1]);
        arr[wire[1]].emplace_back(wire[0]);
    }
    for(auto& wire:wires){
        for(int i=1;i<=n;++i) visited[i] = 0;
        int node1 = wire[0], node2 = wire[1], cnt1 = 0, cnt2 = 0;
        for(int i=1;i<=n;++i){
            if(visited[i]) continue;
            if(cnt1==0) cnt1 = dfs(i, node1, node2);
            else cnt2 =dfs(i, node1, node2);
        }
        ans = min(ans, abs(cnt1-cnt2));
    }
    return ans;
}