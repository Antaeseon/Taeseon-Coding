#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

vector<string> v;
bool chk[27];
int n, k;
int result=0;

void dfs(int cur,int cnt){
    if(k-5<0)
        return;
    
    int now =0;
    if(k-5==cnt){
        for (int i = 0; i < n; i++)
        {
            int correct = 0;
            for (int j = 0; j < v[i].length(); j++)
            {
                if(chk[v[i][j]-'a']){
                    correct++;
                }
            }
            if (correct == v[i].length())
            {
                now++;
            }
        }

        result=max(result,now);
        return;
    }

    for(int i=cur;i<26;i++){
        if (chk[i] == false)
        {
            chk[i]=true;
            dfs(i,cnt+1);
            chk[i]=false;

        }
    }

    

}


int main(){
    string inp;
    
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>inp;
        inp=inp.substr(4,inp.length()-8);
        v.push_back(inp);
    }

    chk['a'-'a']=true;
    chk['n'-'a']=true;
    chk['t'-'a']=true;
    chk['i'-'a']=true;
    chk['c'-'a']=true;

    dfs(0,0);
    cout<<result<<"\n";


}