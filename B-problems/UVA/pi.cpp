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
    lol count;
    while (cin >> count && count)
    {
        lol *arr = new lol[count];
        lol validPairs = 0;
        lol countPairs = (count * (count - 1)) / 2;
        for (int i = 0; i < count; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < count; i++)
        {

            for (int x = i + 1; x < count; x++)
            {
                validPairs += (gcd(arr[i], arr[x]) == 1);
            }
        }
        if (validPairs)
        {
            double res = sqrt((double)((double)(countPairs * 6) / (double)validPairs));
            cout << fixed << setprecision(6) << res << endl;
        }
        else
            cout << "No estimate for this data set." << endl;
    }
}
/*
5
2
3
4
5
6
2
13
39
0
*/