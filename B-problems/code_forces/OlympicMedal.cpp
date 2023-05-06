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

int main()
{
    mino;
    int n;
    cin >> n;
    int max_ = -1;
    for (int i = 0; i < n; ++i)
    {
        int r;
        cin >> r;
        max_ = max(r, max_);
    }
    double r1 = max_;

    int m;
    cin >> m;
    max_ = -1;
    for (int i = 0; i < m; ++i)
    {
        int p;
        cin >> p;
        max_ = max(p, max_);
    }
    double p1 = max_;

    int k;
    cin >> k;
    int min_ = INT32_MAX;
    for (int i = 0; i < k; ++i)
    {
        int p;
        cin >> p;
        min_ = min(p, min_);
    }
    double p2 = min_;
    double A, B;
    cin >> A >> B;
    double ans = ((double)B * p1 * r1 * r1) / ((double)A * p2 + B * p1);
    cout << fixed << setprecision(12) << sqrt(ans);
}