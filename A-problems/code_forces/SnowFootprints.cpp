#include <set>
#include <map>
#include <array>
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
#define mino                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    mino;
    lol size;
    cin >> size;
    string road;
    cin >> road;
    int start, end;
    bool getStart = false, getEnd = false;
    for (int i = 0; i < size; i++)
    {
        if (road[i] == '.')
            continue;

        if (getStart && getEnd)
            break;

        if (!getStart && (road[i] == 'R' || road[i] == 'L'))
        {
            start = i + 1;
            getStart = true;
        }

        if (!getEnd && road[i] == 'R' && (road[i + 1] == '.' || i == size - 1))
        {
            end = i + 2;
            getEnd = true;
        }

        if (!getEnd && road[i] == 'L' && (road[i - 1] == 'R' || i == size - 1))
        {
            end = i;
            getEnd = true;
        }

        if (!getEnd && road[i] == 'L' && (road[i + 1] == '.' || i == size - 1))
        {
            end = start - 1;
            getEnd = true;
        }
    }

    cout << start << " " << end << endl;
}