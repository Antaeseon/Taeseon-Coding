#include<bits/stdc++.h>

using namespace std;

int arr[11][11];
bool visited[11][11];
int N;
int mininum=1e9;


void dfs(int y,int x,int cnt,int res){
    int sum=0;
    
    if(x+1>=N){
        y++;
        x=1;
    }


    if(cnt==3){
        mininum=min(mininum,res);
        return;
    }

    if(y-1<0||y+1>=N||x-1<0||x+1>=N)
        return;
    
    bool chk = true;
    for(int i=y-1;i<y+2;i++){
        for(int j=x-1;j<x+2;j++){
            if(abs(y-i)+abs(x-j)==2)
                continue;
            if(visited[i][j])
                chk=false;
        }
    }
    
    if(chk){
        for (int i = y - 1; i < y + 2; i++)
        {
            for (int j = x - 1; j < x + 2; j++)
            {
                if (abs(y - i) + abs(x - j) == 2)
                    continue;
                visited[i][j]=true;
                sum+=arr[i][j];
            }
        }
        dfs(y,x,cnt+1,res+sum);

        for (int i = y - 1; i < y + 2; i++)
        {
            for (int j = x - 1; j < x + 2; j++)
            {
                if (abs(y - i) + abs(x - j) == 2)
                    continue;
                visited[i][j] = false;
            }
        }

        dfs(y,x+1,cnt,res);
        
    }else{
        dfs(y,x+1,cnt,res);
    }
    
}


int main(){
    cin>>N;
    int inp;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>inp;
            arr[i][j]=inp;
        }
    }
    
    dfs(1,1,0,0);

    cout<<mininum<<"\n";
}