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

enum DayType
{
    rest,
    contest,
    gym
};
const int m = 101;
int memo[m][m];

int count_rest(int *arr, int size, DayType type = rest, int idx = 0)
{
    if (idx == size)
        return 0;

    int path1 = 0, path2 = 0;
    int rests = 0;

    if (memo[idx][type] != -1)
        return memo[idx][type];

    if (arr[idx] == 0)
    {
        path1 = 1 + count_rest(arr, size, rest, idx + 1);
        rests += path1;
    }

    if (arr[idx] == 1)
    {
        if (type != contest)
            path1 = count_rest(arr, size, contest, idx + 1);
        else
            path1 = 1 + count_rest(arr, size, rest, idx + 1);
        rests += path1;
    }

    if (arr[idx] == 2)
    {
        if (type != gym)
            path1 = count_rest(arr, size, gym, idx + 1);
        else
            path1 = 1 + count_rest(arr, size, rest, idx + 1);
        rests += path1;
    }

    if (arr[idx] == 3)
    {
        if (type == rest)
        {
            path1 = count_rest(arr, size, gym, idx + 1);
            path2 = count_rest(arr, size, contest, idx + 1);
            rests += min(path1, path2);
        }
        else
        {
            if (type != gym)
                path1 = count_rest(arr, size, gym, idx + 1);
            if (type != contest)
                path1 = count_rest(arr, size, contest, idx + 1);
            rests += path1;
        }
    }

    return memo[idx][type] = rests;
}

int main()
{
    mino;
    int count;
    cin >> count;
    int *arr = new int[count];
    loop(count) cin >> arr[i];
    loop(m)
    {
        for (int x = 0; x < m; x++)
        {
            memo[i][x] = -1;
        }
    }
    cout << count_rest(arr, count);
}
/*
100
3 2 3 3 3 2 3 1 3 2 2 3 2 3 3 3 3 3 3 1 2 2 3 1 3 3 2 2 2 3 1 0 3 3 3 2 3 3 1 1 3 1 3 3 3 1 3 1 3 0 1 3 2 3 2 1 1 3 2 3 3 3 2 3 1 3 3 3 3 2 2 2 1 3 1 3 3 3 3 1 3 2 3 3 0 3 3 3 3 3 1 0 2 1 3 3 0 2 3 3

*/