#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{ //정렬 custom => 두 수를 합쳤을 경우 더 큰값순으로 정렬
    return a + b > b + a;
}

string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> s_number;

    for (int i = 0; i < numbers.size(); i++)
    {
        s_number.push_back(to_string(numbers[i])); //string으로 변환
    }

    sort(s_number.begin(), s_number.end(), cmp); //custom 정렬

    for (string t : s_number)
    {
        answer += t;
    }
    if (answer[0] == '0')
    { // 첫 수가 0인 경우 0으로 변환
        answer = "0";
    }

    return answer;
}