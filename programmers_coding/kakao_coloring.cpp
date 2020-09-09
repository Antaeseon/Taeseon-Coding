#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
vector<vector<int>> copy_picture;
bool visited[101][101];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int cm;
int cn;

int bfs(int y,int x){
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x]=true;
    int color = copy_picture[y][x];
    int cnt=1;
    while(!q.empty()){
        int tY = q.front().first;
        int tX = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nY = tY +dy[i];
            int nX = tX +dx[i];
            
            if (nY<0||nY>=cm||nX<0||nX>=cn){
                continue;
            }
    
            
            if (copy_picture[nY][nX]==color&&!visited[nY][nX]){
                cnt++;
                visited[nY][nX]=true;
                q.push({nY,nX});
                
            }
        }
        
    }
    return cnt;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    copy_picture = picture;
    cm = m;
    cn = n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(picture[i][j]!=0&&!visited[i][j]){
                number_of_area++;
                int r_value = bfs(i,j);
                max_size_of_one_area = max(max_size_of_one_area,r_value);
            }
        }
    }
    
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main(){
    vector<vector<int>> v = {{1, 1, 1, 0 }, { 1, 1, 1, 0 }, { 0, 0, 0, 1 }, { 0, 0, 0, 1 }, { 0, 0, 0, 1 }, { 0, 0, 0, 1 }};
    vector<int>a = solution(6, 4, v);
    cout << a[0]<<" "<<a[1];

}