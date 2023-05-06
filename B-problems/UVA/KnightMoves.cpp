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
int dirC[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dirR[8] = {1, -1, 2, -2, 2, -2, 1, -1};

bool is_valid(char col, char row)
{
    return (col >= 'a' && col <= 'h') && (row >= '1' && row <= '8');
}
int main()
{
    mino;
    string start, target;
    while (cin >> start >> target)
    {

        queue<pair<string, int>> que;
        que.push({start, 0});
        int steps = 0;

        while (!que.empty())
        {
            string curr_cell = que.front().first;
            int curr_depth = que.front().second;
            que.pop();
            if (target == curr_cell)
            {
                steps = curr_depth;
                break;
            }

            char col = curr_cell[0];
            char row = curr_cell[1];

            for (int i = 0; i < 8; i++)
            {
                char c = (char)(col + dirC[i]);
                char r = (char)(row + dirR[i]);

                if (is_valid(c, r))
                {
                    string child_node = "";
                    child_node += c;
                    child_node += r;
                    que.push({child_node, curr_depth + 1});
                }
            }
        }

        cout << "To get from " << start << " to " << target << " takes " << steps << " knight moves." << endl;
    }
}