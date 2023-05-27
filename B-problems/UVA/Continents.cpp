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

int dirR[] = {0, 0, 1, -1};
int dirC[] = {1, -1, 0, 0};

int row, col;
vector<vector<bool>> visited;
vector<string> grid;
char initLand;

bool validR(int r) { return r >= 0 && r < row; }

int fix(int c)
{
    if (c < 0)
        return col - 1;
    if (c >= col)
        return 0;
    return c;
}

int dfs(int r, int c)
{
    visited[r][c] = true;
    int lands = 1;
    for (int i = 0; i < 4; i++)
    {
        int nr = dirR[i] + r;
        int to_y = fix(dirC[i] + c);
        if (validR(nr) && !visited[nr][to_y] && grid[nr][to_y] == initLand)
            lands += dfs(nr, to_y);
    }
    return lands;
}

int main()
{
    mino;

    while (cin >> row >> col)
    {
        grid = vector<string>(row);
        visited = vector<vector<bool>>(row);
        loop(row)
        {
            cin >> grid[i];
            visited[i] = vector<bool>(col, false);
        }

        int x, y;
        cin >> x >> y;
        initLand = grid[x][y];
        dfs(x, y);

        int lands = 0;

        loop(row)
            loopx(col) if (!visited[i][x] && grid[i][x] == initLand)
        {

            lands = max(lands, dfs(i, x));
        }

        cout << lands << "\n";
    }

    return 0;
}
/*
5 5
wwwww
wwllw
wwwww
wllww
wwwww
1 3
5 5
wwwww
wwllw
wwwww
llwwl
wwwwl
1 3
9 11
wwllwwlwlll
wwwwllwwlww
wwwwlllwwlw
wllwwlwwwww
wwllllwwwwl
wwwwwwwllll
lwwlwlllwll
wwwlllwlllw
wwwwllwlllw
2 5

*/