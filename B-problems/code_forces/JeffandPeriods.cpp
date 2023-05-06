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

int main()
{
    mino;
    lol count;
    cin >> count;
    map<int, vector<int>> freq;
    // bool valid = true;
    for (int i = 0; i < count; i++)
    {
        int x;
        cin >> x;

        freq[x].push_back(i);
    }
    map<int, int> valid;
    loopItr(freq)
    {
        int x = itr->first;

        if (itr->second.size() == 1)
            valid[x] = 0;
        else
        {
            bool ok = true;
            int diff;
            loopR(1, sz(itr->second))
            {
                if (i == 1)
                {
                    diff = itr->second[1] - itr->second[0];
                    continue;
                }

                if (itr->second[i] - itr->second[i - 1] != diff)
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
            {
                valid[x] = diff;
            }
        }
    }

    if (sz(valid) == 0)
    {
        cout << 0;
        return 0;
    }

    cout << sz(valid) << endl;
    loopItr(valid)
    {
        cout << itr->first << " " << itr->second << endl;
    }
}