#include<iostream>

using namespace std;

int dp[1500100];


int main(){
    std::ios::sync_with_stdio(false),cin.tie(0);
    int n;
    int d,p;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>d>>p;
        dp[i+1]=dp[i+1]<dp[i]?dp[i]:dp[i+1];
        dp[i+d]=dp[i+d]>dp[i]+p?dp[i+d]:dp[i]+p;
    }
    cout<<dp[n+1]<<"\n";
    
}
