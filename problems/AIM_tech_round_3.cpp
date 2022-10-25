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
    cin.tie(0);
    cout.sync_with_stdio(0);
}

int main()
{
    fast();

    int orangesNum, maxSize, wasteLimit;
    cin >> orangesNum >> maxSize >> wasteLimit;
    int tank = 0;
    int orangeSize;
    int empties = 0;
    while (orangesNum--)
    {
        cin >> orangeSize;
        if (orangeSize > maxSize)
            continue;

        tank += orangeSize;

        if (tank > wasteLimit)
        {
            empties++;
            tank = 0;
        }
    }

    cout << empties;
}