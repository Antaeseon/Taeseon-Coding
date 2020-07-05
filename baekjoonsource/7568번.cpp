#include<bits/stdc++.h>

using namespace std;


struct person{
    int w;
    int h;
    int rank;
};



int main(){
    std::ios::sync_with_stdio(false),cin.tie(0);
    vector <person>v;
    int n;
    int w,h;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>w>>h;
        v.push_back({w,h,1});
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                continue;
            if(v[i].w<v[j].w&&v[i].h<v[j].h){
                v[i].rank++;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<v[i].rank<<"\n";
    }

}