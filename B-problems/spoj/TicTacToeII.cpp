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
bool is_win(string config)
{
    bool is_full = true;
    for (int i = 0; i < config.size(); i++)
    {
        if (config[i] == '.')
        {
            is_full = false;
            break;
        }
    }
    if (is_full)
    {
        return true;
    }

    bool rows =
        (config[0] != '.' && config[0] == config[1] && config[1] == config[2]) ||
        (config[3] != '.' && config[3] == config[4] && config[4] == config[5]) ||
        (config[6] != '.' && config[6] == config[7] && config[7] == config[8]);

    bool columns =
        (config[0] != '.' && config[0] == config[3] && config[3] == config[6]) ||
        (config[1] != '.' && config[1] == config[4] && config[4] == config[7]) ||
        (config[2] != '.' && config[2] == config[5] && config[5] == config[8]);

    bool diagonals =
        (config[0] != '.' && config[0] == config[4] && config[4] == config[8]) ||
        (config[2] != '.' && config[2] == config[4] && config[4] == config[6]);

    return rows || columns || diagonals;
}

void prepare_valid_config(set<string> &valid)
{
    string start = ".........";
    queue<pair<string, bool>> que;
    que.push({start, true});

    while (!que.empty())
    {
        string curr_config = que.front().first;
        bool curr_player = que.front().second;
        que.pop();
        if (is_win(curr_config))
            continue;

        for (int i = 0; i < 9; i++)
        {
            if (curr_config[i] == '.')
            {
                curr_config[i] = curr_player ? 'X' : 'O';

                if (valid.find(curr_config) == valid.end())
                {
                    que.push({curr_config, !curr_player});
                    valid.insert(curr_config);
                }

                curr_config[i] = '.';
            }
        }
    }
}

int main()
{
    mino;
    set<string> valid;
    prepare_valid_config(valid);
    string board = "";

    while (cin >> board && board != "end")
    {

        string ans = "invalid";

        if (valid.find(board) != valid.end() && is_win(board))
        {
            ans = "valid";
        }

        cout << ans << endl;
    }
}
