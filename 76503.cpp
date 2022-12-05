//모두 0으로 만들기
//https://school.programmers.co.kr/learn/courses/30/lessons/76503

#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define ll long long
using namespace std;

int nodeCnt[300001];
ll weight[300001];
vector<int> edge[300001];
queue<int> q;

long long solution(vector<int> a, vector<vector<int>> edges) {
    ll ans = 0;
    ll sum = 0;
    for (auto& e : edges) {
        edge[e[0]].emplace_back(e[1]);
        edge[e[1]].emplace_back(e[0]);
        nodeCnt[e[0]]++;
        nodeCnt[e[1]]++;
    }
    for (int i = 0; i < a.size(); ++i) {
        if (nodeCnt[i] == 1) q.push(i);
        sum+=(ll) a[i];
        weight[i] = a[i];
    }
    if(sum!=0) return -1;
    while (!q.empty()) {
        int node1 = q.front(); q.pop();
        if (nodeCnt[node1] == 0) continue;
        int node2;
        for (auto n : edge[node1]) {
            if (nodeCnt[n] == 0) continue;
            node2 = n;
            break;
        }
        nodeCnt[node1]--;
        nodeCnt[node2]--;

        weight[node2] += weight[node1];
        ll sum = abs(0 - weight[node1]);
        weight[node1] = 0;
        ans += (ll) sum;
        if (nodeCnt[node2] == 1) q.push(node2);
    }
    
    return ans;
}