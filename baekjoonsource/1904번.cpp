#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    long long res = 2;
    cin >> n;
    int a = 0;
    int b = 1;
    for (int i = 0; i < n; i++)
    {
        res = a + b;
        res %= 15746;
        a = b;
        b = res;
    }

    cout << res << "\n";
}