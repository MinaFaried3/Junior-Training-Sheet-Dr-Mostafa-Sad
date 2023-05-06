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
    cin >> count;
    lol *arr = new lol[count];
    set<lol> different;
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
        different.insert(arr[i]);
    }

    if (different.size() > 3)
    {
        cout << "NO";
        return 0;
    }

    set<lol>::iterator itr;
    lol diff1 = -1, diff2 = -1, prev;
    if (different.size() == 3)
    {
        for (itr = different.begin(); itr != different.end(); itr++)
        {
            if (itr == different.begin())
            {
                prev = *itr;
                continue;
            }

            if (diff1 == -1)
            {
                diff1 = *itr - prev;
                prev = *itr;
                continue;
            }

            if (diff2 == -1)
            {
                diff2 = *itr - prev;
                prev = *itr;
                continue;
            }
        }
    }

    if (diff1 == diff2)
        cout << "YES";
    else
        cout << "NO";
}