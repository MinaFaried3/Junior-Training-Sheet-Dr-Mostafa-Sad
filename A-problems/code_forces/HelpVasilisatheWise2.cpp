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

int r1, r2, c1, c2, d1, d2;
bool check(int n1, int n2, int n3, int n4)
{
    return n1 + n2 == r1 &&
           n3 + n4 == r2 &&
           n1 + n3 == c1 &&
           n2 + n4 == c2 &&
           n1 + n4 == d1 &&
           n2 + n3 == d2;
}
int main()
{
    mino;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;

    for (int n1 = 1; n1 < 10; n1++)
        for (int n2 = 1; n2 < 10; n2++)
        {
            if (n2 == n1)
                continue;
            for (int n3 = 1; n3 < 10; n3++)
            {
                if (n3 == n1 || n3 == n2)
                    continue;
                for (int n4 = 1; n4 < 10; n4++)
                {
                    if (n4 == n1 || n4 == n2 || n4 == n3)
                        continue;

                    if (check(n1, n2, n3, n4))
                    {
                        cout << n1 << " " << n2 << endl
                             << n3 << " " << n4;
                        return 0;
                    }
                }
            }
        }

    cout << -1;
}