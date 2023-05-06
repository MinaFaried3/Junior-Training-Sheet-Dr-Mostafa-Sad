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
#define loop(n) for (int i = 0; i < n; i++)
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

int divisors[1000004]{0};

int count_div(int num)
{
    if (divisors[num] != 0)
        return divisors[num];
    if (num == 1)
        return 1;

    int div = 2;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            if (i == sqrt(num))
                div++;
            else
                div += 2;
        }
    }
    divisors[num] = div;
    return div;
}

int main()
{
    mino;
    int a, b, c;
    cin >> a >> b >> c;
    lol result = 0;
    for (int i1 = 1; i1 <= a; i1++)
        for (int i2 = 1; i2 <= b; i2++)
            for (int i3 = 1; i3 <= c; i3++)
            {
                int num = i1 * i2 * i3;
                result += count_div(num);
            }

    cout << result % 1073741824 ;
}