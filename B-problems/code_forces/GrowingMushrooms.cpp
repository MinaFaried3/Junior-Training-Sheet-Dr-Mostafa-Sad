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

double calc_result(int speed1, int speed2, int time1, int time2, double percentage)
{
    double result = speed1 * time1;
    double reduce = result * percentage;
    result -= reduce;

    result += (double)(speed2 * time2);
    return result;
}
bool order(pair<double, int> curr, pair<double, int> next)
{
    if (curr.first != next.first)
        return curr.first > next.first;

    return curr.second < next.second;
}

int main()
{
    mino;
    int count, time1, time2;
    double percentage;
    cin >> count >> time1 >> time2 >> percentage;
    percentage /= 100;
    pair<double, int> *result = new pair<double, int>[count];

    for (int i = 0; i < count; i++)
    {
        int speed1, speed2;
        cin >> speed1 >> speed2;

        double opt1 = calc_result(speed1, speed2, time1, time2, percentage);
        double opt2 = calc_result(speed2, speed1, time1, time2, percentage);

        result[i].first = max(opt1, opt2);
        result[i].second = i + 1;
    }

    sort(result, result + count, order);

    for (int i = 0; i < count; i++)
    {
        cout << fixed << setprecision(2) << result[i].second << " " << result[i].first << endl;
    }
}