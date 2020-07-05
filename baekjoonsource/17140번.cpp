#include<bits/stdc++.h>

using namespace std;

int arr[101][101];

int main(){
    int r,c,k;
    int inp;
    int res=-1;
    int y=3;
    int x=3;
    cin>>r>>c>>k;
    

    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin>>inp;
            arr[i][j]=inp;
        }
    }
    
    for(int total=0;total<=100;total++){
        if(arr[r][c]==k){
            res=total;
            break;
        }
        vector<pair<int,int>>v[101];
        if(y>=x){ // 행의개수>=열의개수
            for(int row=1;row<=y;row++){
                int arrCnt[101]={0,};
                for(int col=1;col<=x;col++){
                    arrCnt[arr[row][col]]++;
                }

                for(int j=1;j<=100;j++){
                    if(arrCnt[j]>=1){
                        v[row].push_back({arrCnt[j],j});
                    }
                }
            }

            for(int j=1;j<=100;j++){
                for(int k=1;k<=100;k++){
                    arr[j][k]=0;
                }
            }

            for(int i=1;i<=y;i++){
                sort(v[i].begin(),v[i].end());
            }

            for(int i=1;i<=y;i++){
                int index=1;
                for(int j=0;j<v[i].size();j++){
                    arr[i][index++]=v[i][j].second;
                    arr[i][index++]=v[i][j].first;
                    if(index>100)
                        break;
                }
                x = max(x,index-1);
            }


        }else{
            for (int col = 1; col <= x; col++)
            {
                int arrCnt[101] = {
                    0,
                };
                for (int row = 1; row <= y; row++)
                {
                    arrCnt[arr[row][col]]++;
                }

                for (int j = 1; j <= 100; j++)
                {
                    if (arrCnt[j] >= 1)
                    {
                        v[col].push_back({arrCnt[j], j});
                    }
                }
            }

            for (int j = 1; j <= 100; j++)
            {
                for (int k = 1; k <= 100; k++)
                {
                    arr[j][k] = 0;
                }
            }

            for (int i = 1; i <= x; i++)
            {
                sort(v[i].begin(), v[i].end());
            }

            for (int i = 1; i <= x; i++)
            {
                int index = 1;
                for (int j = 0; j < v[i].size(); j++)
                {
                    arr[index++][i] = v[i][j].second;
                    arr[index++][i] = v[i][j].first;
                    if (index > 100)
                        break;
                }
                y = max(y, index - 1);
            }
        }


    }       

    cout<<res<<"\n";



}