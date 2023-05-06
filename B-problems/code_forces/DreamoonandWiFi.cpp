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
int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;

    else
        return n * fact(n - 1);
}
int main()
{
    mino;
    string drazil, dreamoon;
    cin >> drazil >> dreamoon;
    int drazil_final = 0;

    int dreamoon_final = 0;
    int mark = 0;
    for (int i = 0; i < drazil.size(); i++)
    {
        if (drazil[i] == '+')
            drazil_final++;
        if (drazil[i] == '-')
            drazil_final--;

        if (dreamoon[i] == '+')
            dreamoon_final++;
        else if (dreamoon[i] == '-')
            dreamoon_final--;
        else if (dreamoon[i] == '?')
        {
            mark++;
        }
    }

    if (mark == 0)
    {
        if (drazil_final == dreamoon_final)
            cout << fixed << setprecision(12) << 1.0 << endl;
        else
            cout << fixed << setprecision(12) << 0.0 << endl;
        return 0;
    }

    int equ = mark + (drazil_final - dreamoon_final);
    if (equ % 2 == 0 && equ / 2 >= 0 && equ / 2 <= mark)
    {
        int ans = fact(mark) / (fact(mark - equ / 2) * fact(equ / 2));
        cout << fixed << setprecision(12) << double(ans) / double(pow(2, mark)) << endl;
    }
    else
        cout << fixed << setprecision(12) << 0.0 << endl;
}