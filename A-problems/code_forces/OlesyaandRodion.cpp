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
#define LABEL(i, title) cout << " " << i << " - " << title << " :-" << endl
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)

void mino()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve1()
{
    int digits, divisible;
    cin >> digits >> divisible;

    if (divisible == 10)
    {

        if (digits == 1)
        {
            cout << -1;
        }
        else
        {
            cout << 1;
            for (int i = 1; i < digits; i++)
                cout << 0;
        }
        return;
    }

    for (int i = 1; i <= digits; i++)
        cout << divisible;
}

void solve2()
{
    int digits, divisible;
    cin >> digits >> divisible;

    if (divisible == 10)
    {

        if (digits == 1)
        {
            cout << -1;
        }
        else
        {
            cout << 1;
            for (int i = 1; i < digits; i++)
                cout << 0;
        }
        return;
    }

    cout << divisible;
    for (int i = 1; i < digits; i++)
        cout << 0;
}
int main()
{
    mino();
    solve2();
}