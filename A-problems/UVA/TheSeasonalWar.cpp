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

int dirR[8]{0, 0, -1, -1, -1, 1, 1, 1};
int dirC[8]{1, -1, -1, 0, 1, -1, 0, 1};

void mino()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int size_;
bool valid(int r, int c)
{
    return r >= 0 && c >= 0 && r < size_ && c < size_;
}

char grid[30][30];
bool visited[30][30];
void dfs(int rIdx, int cIdx)
{
    if (visited[rIdx][cIdx])
        return;

    visited[rIdx][cIdx] = 1;

    loop0(8)
    {
        int row = rIdx + dirR[i];
        int col = cIdx + dirC[i];

        if (valid(row, col) && !visited[row][col] && grid[row][col] == '1')
            dfs(row, col);
    }
}

int main()
{
    int caseNum{1};

    while (cin >> size_)
    {
        loop(i, size_)
            loop(j, size_)
        {
            cin >>
                grid[i][j];
            visited[i][j] = 0;
        }

        int count = 0;
        loop(i, size_)
            loop(j, size_)
        {
            if (!visited[i][j] && grid[i][j] == '1')
            {
                dfs(i, j);
                count++;
            }
        }

        cout << "Image number " << caseNum++ << " contains " << count << " war eagles." << endl;
    }
}
