#include <set>
#include <map>
#include <array>
#include <list>
#include <iomanip>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <assert.h>
#include <memory.h>
#include <bitset>
using namespace std;

#define lol long long int
#define endl '\n'
#define sz(v) ((lol)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define loop(n) for (int i = 0; i < n; i++)
#define loopx(n) for (int x = 0; x < n; x++)
#define loopR(x, n) for (int i = x; i <= (int)(n); ++i)
#define loopSz(v) for (int i = 0; i < sz(v); ++i)
#define loopItr(structure) for (auto itr = structure.begin(); itr != structure.end(); itr++)
#define BREAK cout << "--------------------------------------------------------------------" << endl
int numIDX = 0;
#define LABEL(title) cout << endl                                        \
                          << ++numIDX << " - " << title << " :-" << endl \
                          << endl;
#define PI 3.14159265358979323846
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)
#define sizeOf(arr) sizeof(arr) / sizeof(arr[0])
#define mino                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
lol gcd(lol a, lol b)
{
    return b == 0 ? a : gcd(b, a % b);
}
lol lcm(lol a, lol b) { return a / gcd(a, b) * b; }

int main()
{
    mino;
    lol side, x, y;
    cin >> side >> x >> y;

    if (y % side == 0 || abs(x) >= side)
    {
        cout << -1;
        return 0;
    }

    lol level = ceil(((double)y / side));
    // cout << level << endl;
    double widthLimit;
    widthLimit = (double)(abs(side)) / 2;
    if (level == 1)
    {
        // cout << widthLimit << endl;
        if (abs(x) < widthLimit)
            cout << level;
        else
            cout << -1;
    }
    else if (level % 2 == 0) // one cell
    {
        if (abs(x) < widthLimit)
            cout << level + ((level / 2) - 1);
        else
            cout << -1;
    }
    else
    {
        if (abs(x) < side && x != 0)
        {
            if (x > 0)
                cout << level + ((level / 2));
            else
                cout << level + ((level / 2) - 1);
        }
        else
            cout << -1;
    }
}

/*
if level is odd have 2 cell
if level is even have 1 cell

1 0 1

3 0 9
*/