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

int dirR[3]{-1, 0, 0};
int dirC[3]{0, 1, -1};
string dirW[3]{"forth", "right", "left"};

void mino()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const string validStones{"IEHOVA#"};
int startR, startC, rows, cols;
vector<string> path;
char grid[9][9];
bool valid(int idxR, int idxC) { return idxR < rows && idxC < cols && idxR >= 0 && idxC >= 0; }
void dfs(int idxR, int idxC, int currStone = 0)
{
    if (currStone == sz(validStones))
        return;

    for (size_t i = 0; i < 3; i++)
    {
        int toR = idxR + dirR[i];
        int toC = idxC + dirC[i];

        if (valid(toR, toC) && grid[toR][toC] == validStones[currStone])
        {
            path.push_back(dirW[i]);
            dfs(toR, toC, currStone + 1);
            break;
        }
    }
}

int main()
{
    mino();
    int tests;
    cin >> tests;
    while (tests--)
    {

        cin >> rows >> cols;
        loop(i, rows)
            loop(j, cols)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '@')
            {
                startR = i;
                startC = j;
            }
        }

        dfs(startR, startC);

        loopSz(i, path)
        {

            cout << path[i];
            if (i != sz(path) - 1)
                cout << " ";
        }

        cout << endl;
        path.clear();
    }
}