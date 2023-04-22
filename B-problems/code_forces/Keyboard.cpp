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

vector<pair<int, int>> posKey[26], shift;
bool can[26]{false};
int distanceX;

int get_distance(int r, int c, int shift_r, int shift_c)
{
    return (r - shift_r) * (r - shift_r) + (c - shift_c) * (c - shift_c);
}

bool check_distance(int r, int c)
{
    for (int i = 0; i < shift.size(); i++)
    {
        int curr_distance = get_distance(r, c, shift[i].first, shift[i].second);
        if (curr_distance <= (distanceX * distanceX))
            return true;
    }

    return false;
}
int main()
{
    mino;
    int rows, cols;
    cin >> rows >> cols >> distanceX;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            char chr;
            cin >> chr;

            if (chr == 'S')
            {
                shift.push_back(make_pair(i, j));
                continue;
            }

            posKey[chr - 'a'].push_back(make_pair(i, j));
        }
    }

    for (int i = 0; i < 26; i++)
    {
        for (int m = 0; m < posKey[i].size() && !can[i]; m++)
        {
            can[i] = can[i] | check_distance(posKey[i][m].first, posKey[i][m].second);
        }
    }

    int query;
    cin >> query;
    int count = 0;
    bool valid = true;
    bool needShift = false;
    while (query--)
    {
        char chr;
        cin >> chr;

        if (chr < 'a')
        {
            needShift = true;
            chr += 32;

            int idx = chr - 'a';
            count += !(can[idx]);
        }

        int idx = chr - 'a';
        if (posKey[idx].size() == 0)
        {
            valid = false;
        }
    }
    if ((shift.size() == 0 && needShift)|| !valid)
        cout << -1;
    else
        cout << count;
}
/*
7 8 5
fqiubjpm
qbshcsyk
cjbxpbef
ptwpmapx
ryazscbm
qnvsgzrf
htardzkz
9
uxrmwkayy
*/