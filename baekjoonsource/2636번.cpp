#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
vector<vector<int>>tmap;
int n, m;

int bfs(int y,int x){
    int cnt = 0;
    bool visited[102][102]={false,};
    queue<pair<int,int>>q;
    q.push({y,x});
    visited[y][x]=true;
    vector<pair<int,int>>rm;
    while(!q.empty()){
        int ty = q.front().first;
        int tx = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny = ty+dy[i];
            int nx = tx+dx[i];
            if(ny<0||ny>=n||nx<0||nx>=m){
                continue;
            }
            if(tmap[ny][nx]==0&&!visited[ny][nx]){
                visited[ny][nx]=true;
                q.push({ny,nx});
            }
            if(tmap[ny][nx]==1&&!visited[ny][nx]){
                visited[ny][nx]=true;
                rm.push_back({ny,nx});
            }
        }

    }

    for(int i=0;i<rm.size();i++){
        tmap[rm[i].first][rm[i].second]=0;
    }
    return rm.size();
}


int main(){
    std::ios::sync_with_stdio(false),cin.tie(0);
    vector<int> cheeseNum;
    int recul=0;
    cin>>n>>m;
    vector<vector<int>> cheese(n + 2, vector<int>(m + 2, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>cheese[i][j];
        }
    }
    tmap=cheese;
    int cnt =0;
    do{
        recul++;
        cnt = bfs(0,0);
        cheeseNum.push_back(cnt);
    } while (cnt);
    cout<<recul-1<<"\n";
    cout<<cheeseNum[cheeseNum.size()-2]<<"\n";
    
    
}