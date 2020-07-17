#include<iostream>
#include<string>
#include<algorithm>


using namespace std;

char map[101][101];

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int main(){
    std::ios::sync_with_stdio(false),cin.tie(0);
    int y=50,x=50,dir=1;
    int moveUp=50,moveDown=50,moveLeft=50,moveRight=50;
    int n;
    string inp;
    cin>>n;
    cin>>inp;
    
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            map[i][j]='#';
        }
    }
    map[y][x]='.';
    for(int i=0;i<n;i++){
        if(inp.at(i)=='F'){
            y+=dy[dir];
            x+=dx[dir];
            map[y][x]='.';
            if(dir==0){
                moveRight=max(moveRight,x);
            }else if(dir==1){
                moveDown=max(moveDown,y);
            }else if(dir==2){
                moveLeft=min(moveLeft,x);
            }else if(dir==3){
                moveUp=min(moveUp,y);
            }

        }else if(inp.at(i)=='L'){
            dir--;
            if(dir==-1){
                dir=3;
            }
        }else if(inp.at(i)=='R'){
            dir = (dir + 1) % 4;
        }
    }
    
    for(int i=moveUp;i<=moveDown;i++){
        for(int j=moveLeft;j<=moveRight;j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }

}