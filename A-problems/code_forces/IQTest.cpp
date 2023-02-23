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
int dirR[3]{0, 1, 1};
int dirC[3]{1, 1, 0};
int main()
{
    mino;
    const int size = 4;
    char **paper = new char *[size];
    for (int i = 0; i < size; i++)
        paper[i] = new char[size];

    for (int i = 0; i < size; i++)
        for (int x = 0; x < size; x++)
            cin >> paper[i][x];

    int countEqual = 0;
    int countNotEqual = 0;

    for (int i = 0; i < size; i++)
    {
        for (int x = 0; x < size; x++)
        {

            for (int d = 0; d < 3; d++)
            {
                int r = i + dirR[d];
                int c = x + dirC[d];

                countEqual += (r < size && c < size && paper[i][x] == paper[r][c]);    // ###.
                countNotEqual += (r < size && c < size && paper[i][x] != paper[r][c]); //.###
            }

            if (countEqual >= 2 || countNotEqual == 3)
            {
                cout << "YES";
                return 0;
            }

            countEqual = 0;
            countNotEqual = 0;
        }
    }

    cout << "NO";
}
/*!SECTION
.###
....
####
....
*/