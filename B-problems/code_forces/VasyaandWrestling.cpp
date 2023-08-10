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
#define loop(i, n) for (int i = 0; i < n; i++)
#define loopx(n) for (int x = 0; x < n; x++)
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
lol toNum(string str)
{
    lol result = 0;
    loopSz(str)
    {
        if (str[i] == '-')
            continue;

        result *= 10;
        result += (str[i] - '0');
    }
    return result;
}
int main()
{
    mino;
    lol n, pos = 0, neg = 0;
    lol cases;
    cin >> cases;
    vector<lol> wrestlers1, wrestlers2;
    bool last = false;
    while (cases--)
    {
        cin >> n;
        if (n > 0)
            wrestlers1.push_back(n), pos += n;
        else
            wrestlers2.push_back(-n), neg += -n;
        last = n > 0;
    };

    if (pos > neg)
        cout << "first";
    else if (neg > pos)
        cout << "second";
    else
    {
        while (!wrestlers1.empty() && !wrestlers2.empty())
        {
            if (wrestlers1.front() > wrestlers2.front())
            {
                cout << "first";
                return 0;
            }
            else if (wrestlers2.front() > wrestlers1.front())
            {
                cout << "second";
                return 0;
            }
            wrestlers1.erase(wrestlers1.begin());
            wrestlers2.erase(wrestlers2.begin());
        }
        if (wrestlers1.empty() && !wrestlers2.empty())
            cout << "second";
        else if (wrestlers2.empty() && !wrestlers1.empty())
            cout << "first";
        else
        {
            cout << (last ? "first" : "second");
        }
    }
}
/*
8
1
-2
-3
4
5
-6
-7
8
*/