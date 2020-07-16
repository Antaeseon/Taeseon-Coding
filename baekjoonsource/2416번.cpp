#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
int N;

int map[101][101];
bool visited[101][101];

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int miniMum=1e9;


void setMap(int y,int x,int num){

    for(int i=0;i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];

        if(ny<0||ny>=N||nx<0||nx>=N)
            continue;

        if(map[ny][nx]!=0&&!visited[ny][nx]){
            visited[ny][nx]=true;
            map[ny][nx]=num;
            setMap(ny,nx,num);
        }
    }
}

struct node{
    int y;
    int x;
    int cnt;
};

int main(){
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int inp;
    int mapNum=1;
    cin>>N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]!=0&&!visited[i][j]){
                visited[i][j]=true;
                map[i][j]=mapNum;
                setMap(i,j,mapNum++);
            }
        }   
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = false;
        }
    }

    for(int i=1;i<mapNum;i++){
        queue<node> q;
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                visited[j][k]=false;
                if(map[j][k]==i){
                    q.push({j,k,1});
                    visited[j][k]=true;
                }
            }
        }

        while(!q.empty()){
            int curX = q.front().x;
            int curY = q.front().y;
            int curCnt = q.front().cnt;
            q.pop();


            if(map[curY][curX]!=0&&map[curY][curX]!=i){
                miniMum=min(miniMum,curCnt);
                break;
            }


            for(int d=0;d<4;d++){
                int nY = curY +dy[d];
                int nX = curX +dx[d];
                if(nY<0||nY>=N||nX<0||nX>=N)
                    continue;
                
                if(!visited[nY][nX]){
                    q.push({nY,nX,curCnt+1});
                    visited[nY][nX]=true;
                }

            }

        }
    }
    cout<<miniMum-2<<"\n";

}