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
void solve1()
{
    //! LONG LONG OVER FLOW
    lol num;
    cin >> num;
    lol result = 0, temp = 0, tens = 1;
    int finalDigit, inverted, digit;
    while (num)
    {
        if (num / 10 == 0 && num == 9) // last digit = 9
            finalDigit = 9;
        else
        {
            digit = (num % 10);
            inverted = 9 - digit;

            finalDigit = min(digit, inverted);
        }

        finalDigit *= tens;
        result = finalDigit + temp;

        num /= 10;
        tens *= 10;
        temp = result;
    }

    cout << result;
}
void solve2()
{
    string num;
    cin >> num;
    for (int i = 0; i < num.size(); i++)
    {
        int digit = num[i] - '0';

        if (digit == 9 && i == 0)
        {
            cout << 9;
            continue;
        }

        int inverted = 9 - digit;
        int finalDigit = min(digit, inverted);
        cout << finalDigit;
    }
}
int main()
{
    mino;
    solve2();
}