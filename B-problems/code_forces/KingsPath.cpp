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

int dirR[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dirC[8] = {0, 1, 0, -1, -1, 1, 1, -1};
set<pair<int, int>> valid_cells;
map<pair<int, int>, int> depth_cells;
bool is_valid(int r, int c)
{
    if (r >= 1 && r <= 1e9 && c >= 1 && c <= 1e9)
    {
        // set<pair<int, int>>::iterator itr;

        if (valid_cells.count({r, c}) != 0)
        {
            return true;
        }
        // for (itr = valid_cells.begin(); itr != valid_cells.end(); itr++)
        // {
        //     pair<int, int> curr = *itr;
        //     if (r == curr.first && c == curr.second)
        //         return true;
        // }
    }

    return false;
}
int main()
{
    mino;

    pair<int, int> start, target;
    cin >> start.first >> start.second >> target.first >> target.second;

    int query;
    cin >> query;
    while (query--)
    {
        int row, col1, col2;
        cin >> row >> col1 >> col2;
        for (int i = col1; i <= col2; i++)
        {
            valid_cells.insert({row, i});
        }
    }

    queue<pair<int, int>> que;
    que.push(start);
    int depth = 0, sz = 1;
    depth_cells[start] = 0;
    int moves = -1;
    for (; !que.empty(); ++depth, sz = que.size())
    {
        while (sz--)
        {
            pair<int, int> curr_node = que.front();

            que.pop();

            for (int i = 0; i < 8; i++)
            {
                int new_r = curr_node.first + dirR[i];
                int new_c = curr_node.second + dirC[i];
                pair<int, int> cell = make_pair(new_r, new_c);
                if (depth_cells.count(cell) == 0 && is_valid(new_r, new_c))
                {
                    que.push(cell);
                    depth_cells[cell] = depth + 1;
                    // cout << new_r << " " << new_c << endl;
                }

                if (cell == target)
                {
                    moves = depth_cells[cell];
                    cout << moves << endl;
                    return 0;
                }
            }
        }
    }

    cout << moves << endl;
}