#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

bool alpha1[26];
bool alpha2[26];

int main(){
    std::ios::sync_with_stdio(false),cin.tie(0);
    string res="";
    int n1,n2;
    string a,b;
    int t;
    cin>>n1>>n2;
    cin>>a>>b;
    cin>>t;
    for(int i=0;i<n1;i++){
        alpha1[a.at(i) - 'A'] = true;
    }

    for(int i=0;i<n2;i++){
        alpha2[b.at(i)-'A']=true;
    }

    reverse(a.begin(),a.end());

    res+=a;
    res+=b;

    for(int i=0;i<t;i++){
        for(int f=0;f<res.length()-1;f++){
            if(alpha1[res.at(f)-'A']&&alpha2[res.at(f+1)-'A']){
                swap(res.at(f),res.at(f+1));
                f++;
            }
        }
    }

    cout<<res<<"\n";


}