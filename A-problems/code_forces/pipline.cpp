#include <set>
#include <map>
#include <array>
#include <list>
#include <iomanip>
#include <cmath>
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
lol sum(lol n)
{
    return (n * (n + 1)) / 2;
}

// sum: s s+1 s+2 ... e
lol sum(lol s, lol e)
{
    if (s <= 1)
        return sum(e);

    return sum(e) - sum(s - 1);
}

lol minSplitters(lol k, lol n)
{
    lol st = 1, en = k;

    while (st < en)
    {
        lol md = (st + en) / 2;
        lol s = sum(md, k);

        if (s == n)
            return k - md + 1;

        if (s > n)
            st = md + 1;
        else
            en = md;
    }

    return k - st + 2;
}

int main()
{
    lol n, k;
    cin >> n >> k;

    if (n == 1)
        cout << 0 << "\n"; // already just 1 out flow source exist
    else if (n <= k)
        cout << 1 << "\n"; // we have 1-n splitter already
    else
    {
        --k;
        --n;

        if (sum(k) < n)
            cout << -1 << "\n";
        else
            cout << minSplitters(k, n) << "\n";
    }

    return 0;
}