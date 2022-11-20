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
void mino()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    mino();
    int count;
    cin >> count;
    int totalCost = 0;
    int *coins = new int[count];
    for (size_t i = 0; i < count; i++)
    {
        cin >> coins[i];
        totalCost += coins[i];
    }

    sort(coins, coins + count);

    int coinsCount = 0, myCost = 0;
    for (size_t i = count - 1; i >= 0; i--)
    {
        totalCost -= coins[i];
        myCost += coins[i];
        coinsCount++;
        if (myCost > totalCost)
            break;
    }

    cout << coinsCount;
}