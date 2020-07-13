#include <iostream>
#include <queue>

using namespace std;

char map[51][51];
bool visited[2][51][51]; // 0 가로 1 세로
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

struct tr
{
    int y;
    int x;
    int dir;
    int cnt=0;
};

int main()
{
    int n;
    cin >> n;
    queue<tr> q;
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'B')
            {
                a++;
            }
            if (a == 2)
            {
                int direction;
                if (map[i - 1][j] == 'B')
                { //세로
                    visited[1][i][j] = true;
                    direction = 1;
                }
                else
                { // 가로
                    visited[0][i][j] = true;
                    direction = 0;
                }
                a = 1e9;
                q.push({i, j, direction});
                visited[direction][i][j]=true;
            }
        }
    }

    while (!q.empty())
    {
        int curY = q.front().y;
        int curX = q.front().x;
        int curDir = q.front().dir;
        int curCnt = q.front().cnt;
        q.pop();

        if(map[curY][curX]=='E'){
            int cor = 0;
            for(int i=-1;i<2;i++){
                if(curDir==0){// 가로
                    if(map[curY][curX+i]=='E'){
                        cor++;
                    }
                }else{
                    if (map[curY+i][curX] == 'E')
                    {
                        cor++;
                    }
                }
            }
            if(cor==3){
                cout<<curCnt<<"\n";
                return 0;
            }
        }

        if (curDir == 0)
        { //가로 
            //1.오른쪽 이동
            if(map[curY][curX+2]!='1'&&curX+2<n && !visited[curDir][curY][curX+1]){
                q.push({curY,curX+1,curDir,curCnt+1});
                visited[curDir][curY][curX+1]=true;
            }    
            //2. 왼쪽 이동
            if (map[curY][curX - 2] != '1' && curX - 2 >= 0 && !visited[curDir][curY][curX - 1])
            {
                q.push({curY, curX - 1, curDir, curCnt + 1});
                visited[curDir][curY][curX - 1] = true;
            }
            //3. 위로 이동
            if (curY - 1 >= 0 && !visited[curDir][curY-1][curX])
            {
                bool tChk=true;
                for(int i= -1; i <2 ;i ++){
                    if(map[curY-1][curX+i]=='1'){
                        tChk=false;
                    }
                }
                if(tChk){
                    q.push({curY-1, curX, curDir, curCnt + 1});
                    visited[curDir][curY-1][curX] = true;
                }
            }
            //4. 아래로 이동
            if (curY + 1 < n && !visited[curDir][curY+1][curX])
            {
                bool tChk = true;
                for (int i = -1; i < 2; i++)
                {
                    if (map[curY + 1][curX + i] == '1')
                    {
                        tChk = false;
                    }
                }
                if (tChk)
                {
                    q.push({curY + 1, curX, curDir, curCnt + 1});
                    visited[curDir][curY + 1][curX] = true;
                }
            }

            //5. 회전
            if (curY - 1 >= 0 && curY + 1 < n && curX - 1 >= 0 && curX + 1 < n && !visited[1][curY][curX])
            {
                bool tChk =true;
                for(int i = -1; i<2;i++){
                    for(int j=-1;j<2;j++){
                        if(map[curY+i][curX+j]=='1'){
                            tChk=false;
                        }

                    }
                }
                if(tChk){
                    q.push({curY,curX,1,curCnt+1});
                    visited[1][curY][curX]=true;
                }
            }
        }
        else
        {   // 세로
            //1.아래쪽 이동
            if (map[curY+2][curX] != '1' && curY + 2 < n && !visited[curDir][curY+1][curX])
            {
                q.push({curY+1, curX, curDir, curCnt + 1});
                visited[curDir][curY+1][curX] = true;
            }
            //2. 위쪽 이동
            if (map[curY-2][curX] != '1' && curY - 2 >= 0 && !visited[curDir][curY-1][curX])
            {
                q.push({curY-1, curX, curDir, curCnt + 1});
                visited[curDir][curY-1][curX] = true;
            }
            //3. 왼쪽 이동
            if (curX - 1 >= 0 && !visited[curDir][curY][curX-1])
            {
                bool tChk = true;
                for (int i = -1; i < 2; i++)
                {
                    if (map[curY +i][curX -1] == '1')
                    {
                        tChk = false;
                    }
                }
                if (tChk)
                {
                    q.push({curY, curX-1, curDir, curCnt + 1});
                    visited[curDir][curY][curX-1] = true;
                }
            }
            //4. 오른쪽 이동
            if (curX + 1 < n && !visited[curDir][curY][curX+1])
            {
                bool tChk = true;
                for (int i = -1; i < 2; i++)
                {
                    if (map[curY + i][curX + 1] == '1')
                    {
                        tChk = false;
                    }
                }
                if (tChk)
                {
                    q.push({curY, curX+1, curDir, curCnt + 1});
                    visited[curDir][curY][curX+1] = true;
                }
            }

            //5. 회전
            if (curY - 1 >= 0 && curY + 1 < n && curX - 1 >= 0 && curX + 1 < n &&!visited[0][curY][curX])
            {
                bool tChk = true;
                for (int i = -1; i < 2; i++)
                {
                    for (int j = -1; j < 2; j++)
                    {
                        if (map[curY + i][curX + j] == '1')
                        {
                            tChk = false;
                        }
                    }
                }
                if (tChk)
                {
                    q.push({curY, curX, 0, curCnt + 1});
                    visited[0][curY][curX] = true;
                }
            }
        }
    }
    cout<<"0\n";
}
