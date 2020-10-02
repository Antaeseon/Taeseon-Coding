#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;
    vector<int> temp_arr;

    // or 연산한 결과 temp_arr에 저장
    for (int i = 0; i < n; i++)
    {
        temp_arr.push_back(arr1[i] | arr2[i]);
    }

    for (int i = 0; i < temp_arr.size(); i++)
    {
        string res = "";
        //n번만큼 temp_arr에 들어있는 값 기준으로 연산
        for (int j = 0; j < n; j++)
        {
            res = ((temp_arr[i] % 2) ? "#" : " ") + res;
            temp_arr[i] /= 2;
        }

        answer.push_back(res);
    }
    return answer;
}