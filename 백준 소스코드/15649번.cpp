#include <iostream>
using namespace std;

int n, m;
bool visited[10];
int arr[10];

void dfs(int index)
{

    if (index == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[index] = i;
            dfs(index + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m; // ex n = 3, m =1
    dfs(0);
}