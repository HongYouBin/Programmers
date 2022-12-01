// 빛의 경로 사이클
// https://school.programmers.co.kr/learn/courses/30/lessons/86052

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> ans;
int visited[500][500][4], dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int rSize, cSize;
void makeCycle(int cnt, int row, int col, int dir, int fR, int fC, int fDir, vector<string>& grid){
    if(row==fR&&col==fC&&dir==fDir&&cnt!=1) {
        ans.emplace_back(cnt-1);    
        return;
    }
    if(visited[row][col][dir]) return;
    visited[row][col][dir] = 1;
        
    if(grid[row][col]=='L') {
        dir--;
        if(dir==-1) dir=3;
    }
    else if(grid[row][col]=='R') dir = (dir+1)%4;
    
    int nxR = row+dx[dir];
    int nxC = col+dy[dir];
    if(nxR==-1) nxR = rSize-1;
    else if(nxR==rSize) nxR = 0;
    if(nxC==-1) nxC = cSize-1;
    else if(nxC==cSize) nxC = 0;
    makeCycle(cnt+1, nxR, nxC, dir,fR, fC, fDir, grid);
}

vector<int> solution(vector<string> grid) {
    rSize = grid.size(); cSize=grid[0].size();
    for(int r=0;r<rSize;++r){
        for(int c=0;c<cSize;++c){
            for(int d=0;d<4;++d){
                if(visited[r][c][d]) continue;
                makeCycle(1, r, c, d, r, c, d, grid);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}