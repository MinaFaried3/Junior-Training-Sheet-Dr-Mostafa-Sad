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
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define loop0(n) for (int i = 0; i < n; i++)
#define loop1(n) for (int i = 1; i <= n; i++)
#define loop(i, n) for (int i = 0; i < (int)(n); ++i)
#define loopSz(i, v) for (int i = 0; i < sz(v); ++i)
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
lol row, col;
bool valid(lol x, lol y)
{
    return x >= 1 and x <= row and y >= 1 and y <= col;
}
const lol limit = 1e9 + 9;
int main()
{
    mino;
    cin >> row >> col;
    lol currR, currC;
    cin >> currR >> currC;
    lol finalSteps = 0;
    lol query;
    cin >> query;
    while (query--)
    {
        lol x, y;
        cin >> x >> y;

        lol left = 1;
        lol right = limit;
        lol steps = 0;
        while (left <= right)
        {
            lol mid = (left + right) / 2;
            if (valid(currR + (mid * x), currC + (mid * y)))
            {
                steps = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        finalSteps += steps;
        currR += (steps * x);
        currC += (steps * y);
    }

    cout << finalSteps;
}