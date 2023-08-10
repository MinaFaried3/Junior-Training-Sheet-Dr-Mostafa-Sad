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

int main()
{
    mino;
    string minStr, maxStr;
    cin >> minStr >> maxStr;

    if (sz(minStr) > sz(maxStr))
        swap(minStr, maxStr);

    lol result = 0;

    int *zeros = new int[sz(maxStr) + 1]{0};
    int *ones = new int[sz(maxStr) + 1]{0};

    for (int i = 1; i <= sz(maxStr); i++)
    {
        zeros[i] = zeros[i - 1] + (maxStr[i - 1] == '0');
        ones[i] = ones[i - 1] + (maxStr[i - 1] == '1');
    }

    lol diffSz = sz(maxStr) - sz(minStr);

    loopSz(minStr)
    {
        if (minStr[i] == '0')
        {
            int neededOnes = ones[i + diffSz + 1] - ones[i];
            result += neededOnes;
        }
        else
        {
            int neededZeros = zeros[i + diffSz + 1] - zeros[i];
            result += neededZeros;
        }
    }

    cout << result;
}