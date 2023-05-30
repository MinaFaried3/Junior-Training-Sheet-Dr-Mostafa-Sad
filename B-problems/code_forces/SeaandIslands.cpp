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
    lol n, k;
    cin >> n >> k;
    lol maxIslands;
    if (n % 2 == 0)
    {
        maxIslands = (n / 2) * n;
    }
    else
    {
        maxIslands = ((n / 2) * (n / 2)) + (((n / 2) + 1) * ((n / 2) + 1));
    }

    if (k > maxIslands)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;

    bool land = true;
    int idx = 0;
    loop(n)
    {
        loopx(n)
        {
            if (k)
            {
                if (i % 2 == 0)
                {
                    if (x % 2 == 0)
                    {
                        cout << 'L';
                        k--;
                    }
                    else
                    {
                         cout << 'S';
                    }
                }
                else
                {
                     if (x % 2 == 1)
                    {
                        cout << 'L';
                        k--;
                    }
                    else
                    {
                         cout << 'S';
                    }
                }
            }
            else
            {
                cout << 'S';
            }
        }

        cout << endl;
    }
}
/*
LSLSL 3
SLSLS 2
LSLSL 3
SLSLS 2
LSLSL 3

LSLS
SLSL
LSLS
SLSL


in even (n / 2) * n
in odd
( n / 2) * n/2
( n / 2) + 1 * ( n / 2) + 1

LSLSLS 3
SLSLSL 3
LSLSLS 3
SLSLSL 3
LSLSLS 3
SLSLSL 3

*/