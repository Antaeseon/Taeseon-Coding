#include<bits/stdc++.h>

using namespace std;

int arr[300][300];



int main(){
    int r,c,k;
    int inp;
    int res=-1;
    cin>>r>>c>>k;
    
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin>>inp;
            arr[i][j]=inp;
        }
    }
    
    for(int i=0;i<100;i++){
        if(arr[r][c]==k){
            res=i;
            break;
        }
    }       

    cout<<res<<"\n";



}