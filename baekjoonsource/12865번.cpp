#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int dp[102][1000001];

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    vector<pair<int,int>>lst;
    int n,m;
    int w,v;
    cin>>n>>m;


    for(int i=0;i<n;i++){
        cin>>w>>v;
        lst.push_back({w,v});
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=lst[i-1].first){
                dp[i][j]=max(dp[i][j],dp[i-1][j-lst[i-1].first]+lst[i-1].second);
            }
        }
    }

    cout<<dp[n][m]<<"\n";

}