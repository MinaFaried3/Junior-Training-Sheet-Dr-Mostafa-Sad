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

const int n = 1e5 + 100;
lol memo[n][2];

lol count_cuts(pair<lol, lol> *trees, lol count, lol idx = 1, int is_right = 0)
{
    if (idx >= count - 1)
        return 0;
    lol &ans = memo[idx][is_right];

    if (ans != -1)
        return ans;

    pair<lol, lol> curr = trees[idx];
    pair<lol, lol> prev = trees[idx - 1];
    pair<lol, lol> next = trees[idx + 1];
    lol xi = curr.first;
    lol hi = curr.second;
    lol x0 = prev.first;
    lol h0 = prev.second;
    lol x1 = next.first;
    lol h1 = next.second;

    // cut left
    if (xi - hi > x0 + is_right * h0)
    {
        ans = max(ans, 1 + count_cuts(trees, count, idx + 1, 0));
    }
    // cut right
    if (xi + hi < x1)
    {
        ans = max(ans, 1 + count_cuts(trees, count, idx + 1, 1));
    }

    // no cutting
    ans = max(ans, count_cuts(trees, count, idx + 1, 0));

    return ans;
}

void solve1()
{
    mino;
    lol count;
    cin >> count;
    pair<lol, lol> *trees = new pair<lol, lol>[count];
    loop(count) cin >> trees[i].first >> trees[i].second;
    loop(n)
    {
        memo[i][0] = -1;
        memo[i][1] = -1;
    }
    if (count <= 2)
        cout << count;
    else
        cout << count_cuts(trees, count) + 2;
}

void solve2()
{
    mino;
    lol count;
    cin >> count;
    pair<lol, lol> *trees = new pair<lol, lol>[count];
    loop(count) cin >> trees[i].first >> trees[i].second;

    if (count <= 2)
        cout << count;
    else
    {
        int cuts = 0;

        for (int i = 1; i < count - 1; i++)
        {
            lol space_before = abs(trees[i].first - trees[i - 1].first);
            lol space_after = abs(trees[i].first - trees[i + 1].first);

            if (trees[i].second < space_before)
                cuts++;
            else if (trees[i].second < space_after)
            {
                cuts++;
                trees[i].first += trees[i].second;
            }
        }
        cout << cuts + 2;
    }
}

int main()
{
    solve2();
    // solve1();
}