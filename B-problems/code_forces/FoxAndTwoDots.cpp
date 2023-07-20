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

int dirR[4]{0, 0, 1, -1};
int dirC[4]{1, -1, 0, 0};
int rows, cols;
char **arr;
int index;
vector<vector<int>> visited, cycle;

bool validRange(int r, int c)
{
    return r >= 0 && c >= 0 && r < rows && c < cols;
}

bool validDFS = false;

void dfs(int r, int c, int fromR, int fromC)
{

    loop(d, 4)
    {
        int newR = r + dirR[d];
        int newC = c + dirC[d];

        if (validRange(newR, newC) && arr[newR][newC] == arr[r][c])
            if (visited[newR][newC] != index)
            {
                visited[newR][newC] = index;
                dfs(newR, newC, r, c);
            }
            else if (cycle[newR][newC] != index && newR != fromR && newC != fromC) // newR != fromR && newC != fromC when return
            {
                validDFS = true;
                return;
            }
        cycle[r][c] = index;
    }
}

int main()
{
    mino;

    cin >> rows >> cols;
    arr = new char *[rows];
    visited = vector<vector<int>>(55, vector<int>(55, 0));
    cycle = vector<vector<int>>(55, vector<int>(55, 0));
    loop(i, rows)
    {
        arr[i] = new char[cols];
        loop(j, cols) cin >> arr[i][j];
    }

    loop(i, rows)
    {
        if (validDFS)
            break;

        loop(j, cols)
        {
            if (validDFS)
                break;

            index = j + i * cols;
            visited[i][j] = index;
            
            dfs(i, j, i, j);
        }
    }

    validDFS ? cout << "Yes" : cout << "No";
}