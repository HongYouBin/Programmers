#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int p[101];

bool comp(vector<int> a, vector<int> b){
    return a[2]<b[2];
}

int findParent(int num){
    if(p[num]!=num) return p[num] = findParent(p[num]);
    return num;
}

void merge(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a==b) return;
    if(a>b) p[a] = b;
    else p[b] = a;
}

int solution(int n, vector<vector<int>> costs) {
    for(int i=0;i<n;++i) p[i] = i;
    
    int ans = 0;
    sort(costs.begin(), costs.end(), comp);
    
    for(auto& i:costs){
        int node1 = i[0];
        int node2 = i[1];
        int cost = i[2];
        if(findParent(node1)!=findParent(node2)){
            merge(node1, node2);
            ans+=cost;
        }
    }
    return ans;
}