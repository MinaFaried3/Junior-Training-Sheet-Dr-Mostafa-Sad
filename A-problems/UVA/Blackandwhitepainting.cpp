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
#include <set>
using namespace std;
#define lol long long int
#define endl '\n'
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.sync_with_stdio(0);
}

int main()
{
    fast();

    int row, col;
    while (cin >> row >> col, row != 0)
    {
        int box;
        cin >> box;
        int newRow, newCol;

        newRow = row - 7;
        newCol = col - 7;

        // divide by 2 to take only white
        lol result = ((newRow * newCol + box) / 2);

        cout << result << endl;
    }
}