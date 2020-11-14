#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++)
    {                               //commands 의 수만큼 반복
        int s = commands[i][0];     // 시작 인덱스
        int f = commands[i][1];     // 끝 인덱스
        int index = commands[i][2]; // 정렬후 원하는 인덱스
        vector<int> temp;

        for (int j = s - 1; j < f; j++)
        {
            temp.push_back(array[j]); //temp 배열에 부분 벡터 저장
        }
        sort(temp.begin(), temp.end());    //저장 후 정렬
        answer.push_back(temp[index - 1]); // 결과값 push
    }

    return answer;
}