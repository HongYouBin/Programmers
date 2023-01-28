//154538
//숫자 변환하기

#include <string>
#include <vector>
#include <queue>

#define inf 1e9
using namespace std;

int visited[1000001];
queue<int> q;

int solution(int x, int y, int n) {
    fill(visited, visited + 1000001, inf);

    q.push(x);
    visited[x] = 0;

    while (!q.empty()) {
        int curNum = q.front(); q.pop();
        if (curNum == y) return visited[curNum];

        int nxNum = curNum + n;
        if (nxNum <= y && visited[nxNum] > visited[curNum] + 1) {
            visited[nxNum] = visited[curNum] + 1;
            q.push(nxNum);
        }
        nxNum = curNum * 2;
        if (nxNum <= y && visited[nxNum] > visited[curNum] + 1) {
            visited[nxNum] = visited[curNum] + 1;
            q.push(nxNum);
        }
        nxNum = curNum * 3;
        if (nxNum <= y && visited[nxNum] > visited[curNum] + 1) {
            visited[nxNum] = visited[curNum] + 1;
            q.push(nxNum);
        }
    }
    return -1;
}