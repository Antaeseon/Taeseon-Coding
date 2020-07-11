#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(int &a,int &b){
    return a>b;
}


int main(){
    int n;
    int inp;
    int sum=0;
    vector<int> a;
    vector<int> b;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>inp;
        a.push_back(inp);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        b.push_back(inp);
    }
    sort(a.begin(),a.end(),cmp);
    sort(b.begin(),b.end());

    for(int i=0;i<n;i++){
        sum+=(a[i]*b[i]);
    }
    cout<<sum<<"\n";
}