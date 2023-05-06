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

lol binary_search(lol *arr, lol start, lol end, lol val)
{
    lol idx;

    while (start <= end)
    {
        lol mid = (start + end) / 2;

        if (arr[mid] <= val * 2)
        {
            idx = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return idx;
}
void solve1()
{
    mino;
    lol count;
    cin >> count;

    lol *arr = new lol[count];
    for (lol i = 0; i < count; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + count);
    lol removes, idx;
    for (lol i = 0; i < count; i++)
    {
        idx = binary_search(arr, i, count - 1, arr[i]);
        if (i == 0)
        {
            removes = i + (count - idx - 1);
            continue;
        }

        removes = min(removes, i + (count - idx - 1));
    }
    cout << removes << endl;
}
void solve2()
{

    int n, x, a[100005], ans = INT_MAX;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    /// 3 3 4 5 7 8
    for (int i = 0; i < n; i++)
    {
        x = upper_bound(a, a + n, a[i] * 2) - a;
        ans = min(ans, i + n - x);
    }
    cout << ans << endl;
}
int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    solve1();
}