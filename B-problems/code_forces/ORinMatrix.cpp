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
    int rows, cols;
    cin >> rows >> cols;

    int **arr = new int *[rows];
    int **res = new int *[rows];
    loop(i, rows)
    {
        arr[i] = new int[cols];
        res[i] = new int[cols];
        loop(j, cols)
        {
            cin >> arr[i][j];
            res[i][j] = 8;
        }
    }

    loop(i, rows)
    {
        loop(j, cols)
        {
            if (arr[i][j] == 0)
            {
                loop(x, cols)
                {
                    res[i][x] = 0;
                }

                loop(x, rows)
                {
                    res[x][j] = 0;
                }
            }

            if (arr[i][j] == 1)
            {
                loop(x, cols)
                {
                    if (res[i][x] == 8)
                    {
                        res[i][x] = 1;
                    }
                }

                loop(x, rows)
                {
                    if (res[x][j] == 8)
                    {
                        res[x][j] = 1;
                    }
                }
            }
        }
    }
    bool valid = true;
    loop(i, rows)
    {
        if (!valid)
            break;
        loop(j, cols)
        {
            if (!valid)
                break;

            if (arr[i][j] == 0)
            {
                // cout << "res[" << i << "][" << j << "] " << res[i][j] << endl
                //      << endl;
                loop(x, cols)
                {
                    // cout << "x,cols res[" << i << "][" << x << "] " << res[i][x] << endl;
                    if (res[i][x] != 0)
                    {
                        valid = false;
                        break;
                    }
                }

                loop(x, rows)
                {
                    // cout << "x,rows res[" << x << "][" << j << "] " << res[x][j] << endl;
                    if (res[x][j] != 0)
                    {
                        valid = false;
                        break;
                    }
                }
            }

            if (arr[i][j] == 1)
            {
                bool found = false;
                loop(x, cols)
                {
                    if (res[i][x] == 1)
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                    loop(x, rows)
                    {
                        if (res[x][j] == 1)
                        {
                            found = true;
                            break;
                        }
                    }

                if (!found)
                    valid = false;
            }
        }
    }

    if (!valid)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    loop(i, rows)
    {
        loop(j, cols)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}