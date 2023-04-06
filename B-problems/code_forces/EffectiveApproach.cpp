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
void solve1()
{
    lol size;
    cin >> size;

    map<lol, pair<lol, lol>> mp;

    loop1(size)
    {
        lol num;
        cin >> num;

        mp[num] = {i, (size + 1) - i};
    }

    lol query;
    cin >> query;
    lol left = 0, right = 0;
    while (query--)
    {
        lol num;
        cin >> num;

        left += mp[num].first;
        right += mp[num].second;
    }

    cout << left << " " << right << endl;
}

void solve2()
{

    lol size;
    cin >> size;

    lol freq[100001];

    loop1(size)
    {
        lol num;
        cin >> num;
        freq[num] = i;
    }

    lol query;
    cin >> query;
    lol left = 0, right = 0;
    while (query--)
    {
        lol num;
        cin >> num;

        left += freq[num];
        right += size - freq[num] + 1;
    }

    cout << left << " " << right << endl;
}
int main()
{
    mino;
    solve2();
}