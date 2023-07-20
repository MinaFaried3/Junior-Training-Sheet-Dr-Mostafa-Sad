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
#define sz(v) ((lol)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define loop(i, n) for (int i = 0; i < n; i++)
#define loopx(n) for (int x = 0; x < n; x++)
#define loopR(x, n) for (int i = x; i <= (int)(n); ++i)
#define loopSz(v) for (int i = 0; i < sz(v); ++i)
#define loopItr(structure) for (auto itr = structure.begin(); itr != structure.end(); itr++)
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

lol zeros = 0;
bool haveZero = false;
bool notBeautiful = false;
string bigNum;
void countZero(string num)
{
    if (num == "0" || haveZero)
    {
        haveZero = true;
        return;
    }
    lol currZeroes = 0;
    lol res = 0;
    lol i;
    for (i = sz(num) - 1; i >= 0; i--)
    {
        if (num[i] == '0')
            currZeroes++;
        else
            break;
    }

    if (!notBeautiful)
    {
        lol ones = 0;
        for (lol x = 0; x <= i; x++)
        {
            if (num[x] == '1')
                ones++;

            if (ones > 1 || num[x] != '1')
            {
                bigNum = num;
                notBeautiful = true;
                return;
            }
        }
    }

    zeros += currZeroes;
}

int main()
{
    mino;
    lol cases;
    cin >> cases;

    while (cases--)
    {
        string num;
        cin >> num;

        countZero(num);
    }

    if (haveZero)
    {
        cout << 0;
        return 0;
    }
    if (notBeautiful)
        cout << bigNum;
    else
        cout << 1;
    while (zeros--)
    {
        cout << 0;
    }
}
/*
40
10 100 10 1 10 10 100 10 10 100 10 100 100 10 1824868942 100 100 1 10 100 100 10 100 100 10 100 10 1 10 100 100 100 10 1 10 1 10 10 100 100

6
1000000000000 6643573784 10000000000 100000000000000 1000000000000000 1000000000000000000000000


5
10 100 10000 1000 100
*/