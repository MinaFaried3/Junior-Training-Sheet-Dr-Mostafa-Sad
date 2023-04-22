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

int main()
{
    mino;

    lol days, choosen;
    cin >> days >> choosen;
    lol *maybe_choose = new lol[days]{0};
    lol sum = 0;
    lol product, clients;
    for (int i = 0; i < days; i++)
    {
        cin >> product >> clients;
        sum += min(product, clients);
        if (clients > product)
        {
            maybe_choose[i] = min(2 * product, clients) - min(product, clients);
        }
        else
        {
            maybe_choose[i] = 0;
        }
    }

    sort(maybe_choose, maybe_choose + days, greater<lol>());
    for (int i = 0; i < days; i++)
    {
        if (choosen > 0)
        {
            sum += maybe_choose[i];
            // cout << sum << endl;
            choosen--;
        }
        else
        {
            break;
        }
    }

    cout << sum << endl;
}