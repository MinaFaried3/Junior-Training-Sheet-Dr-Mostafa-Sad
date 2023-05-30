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

vector<lol> combinations;
lol nums;
lol k;
vector<lol> problems;
lol suitableProblemSet = 0;
lol problemCount, minTotal, maxTotal, diff;
void get_combination(int size = 0, int last_idx = -1)
{
    if (size == k)
    {
        lol min_, max_;
        lol sum = 0;
        loop(sz(combinations))
        {
            if (i == 0)
            {
                min_ = max_ = combinations[i];
            }
            sum += combinations[i];
            min_ = min(min_, combinations[i]);
            max_ = max(max_, combinations[i]);
        }
        // cout << min_ << " " << max_ << " " << sum << endl;

        suitableProblemSet += ((max_ - min_ >= diff) && sum >= minTotal && sum <= maxTotal);

        return;
    }

    for (int x = last_idx + 1; x < nums; x++)
    {
        combinations.push_back(problems[x]);

        get_combination(size + 1, x);

        combinations.pop_back();
    }
}

int main()
{
    mino;

    cin >> problemCount >> minTotal >> maxTotal >> diff;

    problems = vector<lol>(problemCount);
    loop(problemCount) cin >> problems[i];
    nums = problemCount;

    for (int n = 2; n <= problemCount; n++)
    {
        k = n;
        get_combination();
    }

    cout << suitableProblemSet;
}