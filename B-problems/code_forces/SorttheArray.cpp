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
void solve1()
{
    lol count;
    cin >> count;

    lol *arr = new lol[count];
    lol *sorted = new lol[count];

    /*
    9
    6 78  59 63 28 24 8 96 99

    */
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
        sorted[i] = arr[i];
    }
    sort(sorted, sorted + count);
    bool isStart = false, isEnd = false;
    int start_idx = 0, end_idx = 0;
    bool valid = true;
    for (int i = 0; i < count; i++)
    {

        if (arr[i] != sorted[i] && !isStart)
        {
            isStart = true;
            start_idx = i;
            continue;
        }
        if (arr[i] != sorted[i] && isStart)
        {
            isEnd = true;
            end_idx = i;
            continue;
        }
    }

    reverse(arr + start_idx, arr + end_idx + 1);
    int rev = 0;
    for (int i = start_idx; i <= end_idx; i++)
    {
        if (arr[i] != sorted[i])
        {
            valid = false;
            break;
        }
        rev++;
    }

    if (valid)
        cout << "yes" << endl
             << start_idx + 1 << " " << end_idx + 1 << endl;
    else
        cout << "no";
}
void solve2()
{
    lol count;
    cin >> count;

    lol *arr = new lol[count];
    lol *sorted = new lol[count];

    /*
    9
    6 78  59 63 28 24 8 96 99

    */
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
        sorted[i] = arr[i];
    }
    sort(sorted, sorted + count);
    bool isStart = false, isEnd = false;
    int start_idx = 0, end_idx = 0;
    bool valid = true;
    for (int i = 0; i < count; i++)
    {

        if (arr[i] != sorted[i] && !isStart)
        {
            isStart = true;
            start_idx = i;
            continue;
        }
        if (arr[i] != sorted[i] && isStart)
        {
            isEnd = true;
            end_idx = i;
            continue;
        }
    }

    int rev = 0;
    for (int i = start_idx; i <= end_idx; i++)
    {
        if (arr[i] != sorted[end_idx - rev])
        {
            valid = false;
            break;
        }
        rev++;
    }
    if (valid)
        cout << "yes" << endl
             << start_idx + 1 << " " << end_idx + 1 << endl;
    else
        cout << "no";
}
int main()
{
    mino;
    solve2();
}