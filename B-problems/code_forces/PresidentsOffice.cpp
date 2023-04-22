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

int dirR[4]{-1, 0, 0, 1};
int dirC[4]{0, -1, 1, 0};

int main()
{
    mino;
    int rows, cols;
    cin >> rows >> cols;
    char president;
    cin >> president;

    char **arr = new char *[rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new char[cols];
        for (int x = 0; x < cols; x++)
        {
            cin >> arr[i][x];
        }
    }
    set<char> deputies;

    for (int i = 0; i < rows; i++)
    {
        for (int x = 0; x < cols; x++)
        {
            if (arr[i][x] == president)
            {
                for (int d = 0; d < 4; d++)
                {
                    int dr = i + dirR[d];
                    int dc = x + dirC[d];

                    if (dr < rows && dc < cols && dr >= 0 && dc >= 0 && arr[dr][dc] != '.' && arr[dr][dc] != president)
                    {
                        deputies.insert(arr[dr][dc]);
                    }
                }
            }
        }
    }

    cout << deputies.size();
}