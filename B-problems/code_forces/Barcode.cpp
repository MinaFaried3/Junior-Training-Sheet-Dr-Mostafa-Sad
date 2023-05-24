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
int n, m, x, y;

// n - dotsCount[i] = # of hashes
int dotsCount[1000 + 9];         // +9 for safety and little thinking
int memo[1000 + 9][1000 + 9][3]; // 3: 0 (dots), 1 (hashes), 2 (nothing)

// 0-1 style with restrictions on # of connectives of same value
int solve(int col, int wid, int last)
{
    if (col == m)
    {
        // Make sure invalid states to invalidated
        if (wid < x || wid > y)
            return 100000000;
        return 0; // we are done
    }

    int &ans = memo[col][wid][last];

    if (ans != -1)
        return ans;

    int dots = 100000000; // max answer is 1000x1000
    // nothing before or bigger block is valid or old block is allowed
    if (col == 0 || (last == 0 && wid + 1 <= y) || (last == 1 && wid >= x))
        dots = n - dotsCount[col] + solve(col + 1, (last == 0) ? wid + 1 : 1, 0);

    int hashes = 100000000;
    if (col == 0 || (last == 1 && wid + 1 <= y) || (last == 0 && wid >= x))
        hashes = dotsCount[col] + solve(col + 1, (last == 1) ? wid + 1 : 1, 1);

    ans = min(dots, hashes);

    return ans;
}
// Your turn: Convert to tabulation style

int main()
{
#ifndef ONLINE_JUDGE
    freopen("test.txt", "rt", stdin);
#endif

    cin >> n >> m >> x >> y;

    // read and accumulate each column
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            char ch;
            cin >> ch;

            if (ch == '.')
                dotsCount[j]++;
        }
    }

    full(memo, -1);
    cout << solve(0, 0, 2);

    return 0;
}