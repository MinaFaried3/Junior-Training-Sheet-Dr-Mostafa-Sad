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

void solve1()
{
    int left, right, amb;
    cin >> left >> right >> amb;

    int minNum = min(left, right);
    int maxNum = max(left, right);

    int needed = maxNum - minNum;

    if (needed == amb)
    {
        minNum += amb;
        cout << minNum + maxNum;
    }
    else if (needed > amb)
    {
        minNum += amb;
        cout << minNum * 2;
    }
    else
    {
        minNum += needed;
        amb -= needed;

        int remain = amb / 2;
        minNum += remain;
        maxNum += remain;

        cout << minNum + maxNum;
    }
}

void solve2()
{
    int left, right, amb;
    cin >> left >> right >> amb;

    while (amb > 0)
    {
        if (left < right)
            left++;
        else
            right++;

        amb--;
    }

    cout << min(left, right) * 2;
}

int main()
{
    mino;
    solve2();
}