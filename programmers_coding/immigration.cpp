
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
    //이분탐색을 하기 위해 정렬
    sort(times.begin(), times.end());
    //minimum 값과 maximum 값 초기화
    long long mi = 1;
    long long ma = (long long)times[times.size() - 1] * (long long)n;

    while (mi < ma)
    {
        long long mid = (mi + ma) / 2;
        long long boat = 0;

        for (long long i = 0; i < times.size(); i++)
        {
            boat += (mid / times[i]); // 총 보트의 수 계산
        }
        if (boat >= n)
        { //보트가 같거나 많은경우 => maximum을 줄여야함
            ma = mid;
        }
        else
        { // mid 증가 위해 minimum 증가
            mi = mid + 1;
        }
    }
    return ma;
}