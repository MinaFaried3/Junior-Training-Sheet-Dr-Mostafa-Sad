#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <tuple>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define lol long long int
#define endl '\n'
void fast()
{
    cin.tie(0);
    cout.sync_with_stdio(0);
}

int main()
{
    fast();

    int arr[5][5];
    int row, col;
    for (int i = 0; i < 5; i++)
        for (int x = 0; x < 5; x++)
        {
            cin >> arr[i][x];
            if (arr[i][x] == 1)
            {
                row = i;
                col = x;
                break;
            }
        }
    int moves = 0;
    moves += abs(2 - row);
    moves += abs(2 - col);

    cout << moves;
}