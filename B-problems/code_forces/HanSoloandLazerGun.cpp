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
void solve1()
{
    int enemies, x0, y0;
    cin >> enemies >> x0 >> y0;

    map<pair<int, int>, bool> points;
    while (enemies--)
    {
        int x, y;
        cin >> x >> y;
        points[{x, y}] = false;
    }
    int result = 0;

    loopItr(points)
    {
        pair<int, int> enemy1 = itr->first;
        if (points[enemy1] == false)
        {
            result++;
            points[enemy1] = true;
            auto i = next(itr, 1);
            for (i; i != points.end(); i++)
            {
                pair<int, int> enemy2 = i->first;

                int equ1 = (y0 - enemy1.second) * (x0 - enemy2.first);
                int equ2 = (y0 - enemy2.second) * (x0 - enemy1.first);

                if (equ1 == equ2)
                    points[enemy2] = true;
            }
        }
    }

    cout << result << endl;
}

void solve2()
{
    int count, x0, y0;
    cin >> count >> x0 >> y0;

    set<pair<int, int>> shots;
    while (count--)
    {
        int x, y;
        cin >> x >> y;
        bool sign = false;

        int dy = y0 - y;
        int dx = x0 - x;

        if (dy < 0 && dx > 0)
            sign = true;

        if (dy > 0 && dx < 0)
            sign = true;

        dy = abs(dy);
        dx = abs(dx);
        int gcd_ = gcd(dy, dx);
        dy /= gcd_;
        dx /= gcd_;

        if (sign)
            dy *= -1;

        shots.insert({dy, dx});
    }

    cout << shots.size();
}
int main()
{
    mino;
    solve2();
}