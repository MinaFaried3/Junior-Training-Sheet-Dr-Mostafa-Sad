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

lol fact(lol start, lol end)
{
    lol res = 1;
    for (int i = start; i <= (int)(end); ++i)
        res *= i;

    return res;
}

void solve1()
{
    lol n, m;
    while (cin >> n >> m && n != 0 && m != 0)
    {
        lol w = min((n - m), m);
        vector<int> numerator, denominator;

        lol sum = 1, sum2 = 1;
        for (lol i = n; i > (n - w); i--)
            numerator.push_back(i);
        for (lol i = w; i > 0; i--)
            denominator.push_back(i);
        for (int i = 0; i < numerator.size(); i++)
        {
            for (int j = 0; j < denominator.size(); j++)
            {
                int q = gcd(numerator[i], denominator[j]);
                if (q != 1)
                {
                    numerator[i] /= q;
                    denominator[j] /= q;
                }
            }
        }
        for (int i = 0; i < numerator.size(); i++)
        {
            sum *= numerator[i];
        }
        for (int i = 0; i < denominator.size(); i++)
            sum2 *= denominator[i];
        cout << n << " things taken " << m << " at a time is " << sum / sum2 << " exactly.\n";
    }
}

void solve2()
{
    lol pascalTriangle[103][103]{0};

    pascalTriangle[1][0] = 1;
    pascalTriangle[1][1] = 1;

    for (int i = 2; i <= 100; i++)
    {
        pascalTriangle[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            pascalTriangle[i][j] = pascalTriangle[i - 1][j] + pascalTriangle[i - 1][j - 1];
        }
    }

    lol n, m;
    while (cin >> n >> m && n != 0 && m != 0)
    {
        cout << n << " things taken " << m << " at a time is " << pascalTriangle[n][m] << " exactly.\n";
    }
}
int main()
{
    mino;
    solve2();
}