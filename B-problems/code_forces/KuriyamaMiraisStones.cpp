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
    lol count;
    cin >> count;

    lol *arr = new lol[count + 1];
    lol *prefix_arr = new lol[count + 1];
    arr[0] = 0;
    prefix_arr[0] = 0;
    lol num;

    for (int i = 1; i <= count; i++)
    {
        cin >> arr[i];
        prefix_arr[i] = arr[i] + prefix_arr[i - 1];
    }

    sort(arr, arr + count + 1);
    for (int i = 1; i <= count; i++)
    {

        arr[i] += arr[i - 1];
    }

    lol query;
    cin >> query;
    while (query--)
    {
        int type, left, right;
        cin >> type >> left >> right;
        lol result;
        if (type == 1)
        {
            result = prefix_arr[right] - prefix_arr[left - 1];
        }
        else
        {
            result = arr[right] - arr[left - 1];
        }

        cout << result << endl;
    }
}