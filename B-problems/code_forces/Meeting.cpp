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
#include <float.h>
#include <bitset>
using namespace std;

#define lol long long int
#define endl '\n'
#define sz(v) ((lol)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define loop(n) for (int i = 0; i < n; i++)
#define loopR(x, n) for (int i = x; i < (int)(n); ++i)
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
double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

vector<tuple<double, double, double>> radiators;

bool check(double x, double y)
{
    for (double i = 0; i < sz(radiators); i++)
    {
        double xr, yr, rr;
        xr = get<0>(radiators[i]);
        yr = get<1>(radiators[i]);
        rr = get<2>(radiators[i]);
        if (dist(x, y, xr, yr) <= rr)
            return 0;
    }

    return 1;
}
int main()
{
    mino;
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double x1 = min(a, c);
    double x2 = max(a, c);
    double y1 = min(b, d);
    double y2 = max(b, d);
    double count;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        double x, y, r;
        cin >> x >> y >> r;
        radiators.push_back(make_tuple(x, y, r));
    }

    int blanket = 0;

    for (int i = x1; i <= x2; i++)
    {
        bool valid1 = check(i, y1);
        bool valid2 = check(i, y2);

        blanket += valid1 + valid2;
    }
    for (int i = y1 + 1; i <= y2 - 1; i++)
    {
        bool valid1 = check(x1, i);
        bool valid2 = check(x2, i);

        blanket += valid1 + valid2;
    }

    cout << blanket;
}