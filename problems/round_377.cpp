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

    int tenCoin, oneCoin;
    cin >> tenCoin >> oneCoin;

    int shovels = 0;
    for (size_t i = 1;; i++)
    {
        if ((tenCoin * i) % 10 == oneCoin || (tenCoin * i) % 10 == 0)
        {
            shovels = i;
            break;
        }
    }

    cout << shovels << endl;
}