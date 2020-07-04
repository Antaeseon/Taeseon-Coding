#include<bits/stdc++.h>

using namespace std;
int arr[51][51];
int temparr[51][51];
//E,N,W,S
int dx[4] ={1,0,-1,0};
int dy[4]= {0,-1,0,1};
int sum = 0;

struct dust{
    int y;
    int x;
    int amt;
};

int main(){
    std::ios::sync_with_stdio(false),cin.tie(0);
    int r,c,t;
    int inp;
    vector<pair<int,int>>v;
    cin>>r>>c>>t;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>inp;
            arr[i][j]=inp;
        }
    }
    while(t--){
        queue<dust> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr[i][j]>=5){
                    q.push({i,j,arr[i][j]});
                }
                if(arr[i][j]==-1){
                    v.push_back({i,j});
                }
            }
        }

        while(!q.empty()){
            int tempY = q.front().y;
            int tempX = q.front().x;
            int tempAmt = q.front().amt;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nY = tempY +dy[i];
                int nX = tempX +dx[i];
                if(nY<0||nX<0||nY>=r||nX>=c||arr[nY][nX]==-1)
                    continue;

                arr[nY][nX]+=(tempAmt/5);
                arr[tempY][tempX]-=(tempAmt/5);
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                temparr[i][j]=arr[i][j];
            }
        }

        //반시계방향
        int curY = v[0].first;
        int curX = v[0].second+1;
        arr[curY][curX]=0;
        for(int i=0;i<4;i++){
            while(1){
                int nY = curY+dy[i];
                int nX = curX+dx[i];

                if(nY==v[0].first&&nX==v[0].second)
                    break;
                if(nY>=r||nX>=c||nY<0||nX<0)
                    break;
                arr[nY][nX]=temparr[curY][curX];
                curY=nY;
                curX=nX;
                
            }
        }

        //0 3 2 1
        curY = v[1].first;
        curX = v[1].second + 1;
        arr[curY][curX] = 0;
        for (int i = 4; i > 0; i--)
        {
            while (1)
            {
                int nY = curY + dy[i%4];
                int nX = curX + dx[i%4];

                if (nY == v[1].first && nX == v[1].second)
                    break;
                if (nY >= r || nX >= c || nY < 0 || nX < 0)
                    break;

                arr[nY][nX]=temparr[curY][curX];
                curY = nY;
                curX = nX;
            }
        }
    }

    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == -1)
                continue;
            sum += arr[i][j];
        }
    }

    cout << sum << "\n";
}