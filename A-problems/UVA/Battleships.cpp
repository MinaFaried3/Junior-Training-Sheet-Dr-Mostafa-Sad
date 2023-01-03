#include <set>
#include <map>
#include <list>
#include <iomanip>
#include <cmath>
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
#define loop0(n) for (size_t i = 0; i < n; i++)
#define loop(i, n) for (int i = 0; i < (int)(n); ++i)
#define loopSz(i, v) for (int i = 0; i < sz(v); ++i)
#define BREAK cout << "--------------------------------------------------------------------" << endl
#define LABEL(i, title) cout << " " << i << " - " << title << " :-" << endl
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)

void mino()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int dirR[4]{0, 0, 1, -1};
int dirC[4]{1, -1, 0, 0};
int startR, startC, rows, cols;
vector<string> path;
char grid[101][101];
bool visited[101][101]{0};
bool valid(int idxR, int idxC) { return idxR < rows && idxC < cols && idxR >= 0 && idxC >= 0; }
void dfs(int idxR, int idxC)
{
    if (visited[idxR][idxC])
        return;
    visited[idxR][idxC] = true;
    for (size_t i = 0; i < 4; i++)
    {
        int toR = idxR + dirR[i];
        int toC = idxC + dirC[i];
        char chr = grid[idxR][toC];
        if (valid(toR, toC) && (chr == 'x' || chr == '@'))
            dfs(toR, toC);
    }
}

int main()
{
    mino();
    int tests;
    cin >> tests;
    loop0(tests)
    {
        cin >> rows;
        cols = rows;
        loop(i, rows)
            loop(j, cols)
        {
            cin >> grid[i][j];
            visited[i][j] = false;
        }

        int alive = 0;
        loop(i, rows)
            loop(j, cols)
        {
            if (visited[i][j] == false && grid[i][j] == 'x')
            {
                alive++;
                dfs(i, j);
            }
        }

        cout << "Case " << i + 1 << ": " << alive << endl;
    }
}