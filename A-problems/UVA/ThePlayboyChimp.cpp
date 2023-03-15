#include <set>
#include <map>
#include <array>
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
#define sizeOf(arr) sizeof(arr) / sizeof(arr[0])
#define mino                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

lol findShorter(lol *arr, lol size, lol wanted)
{
    lol start = 0;
    lol end = size - 1;
    while (start <= end)
    {
        lol mid = (start + end) / 2;
        if (arr[mid] < wanted)
            start = mid + 1;
        else if (arr[mid] >= wanted)
            end = mid - 1;
    }
    if (end < 0)
        return -1;
    return arr[end];
}
lol findTaller(lol *arr, lol size, lol wanted)
{
    lol start = 0;
    lol end = size - 1;
    while (start <= end)
    {
        lol mid = (start + end) / 2;
        if (arr[mid] <= wanted)
            start = mid + 1;
        else if (arr[mid] > wanted)
            end = mid - 1;
    }
    if (start >= size)
        return -1;
    return arr[start];
}
void solve1()
{
    lol size;
    cin >> size;
    lol *arr = new lol[size];

    for (int i = 0; i < size; i++)
        cin >> arr[i];

    lol queries;
    cin >> queries;
    while (queries--)
    {
        lol height;
        cin >> height;

        lol left = findShorter(arr, size, height);
        lol right = findTaller(arr, size, height);

        if (left == -1)
            cout << "X";
        else
            cout << left;

        cout << " ";

        if (right == -1)
            cout << "X";
        else
            cout << right;

        cout << endl;
    }
}

void solve2()
{
    lol size;
    cin >> size;
    vector<lol> vec(size);

    for (int i = 0; i < size; i++)
        cin >> vec[i];

    lol queries;
    cin >> queries;
    while (queries--)
    {
        lol height;
        cin >> height;

        vector<lol>::iterator left = lower_bound(vec.begin(), vec.end(), height);
        vector<lol>::iterator right = upper_bound(vec.begin(), vec.end(), height);

        int leftIdx = left - vec.begin();
        int rightIdx = right - vec.begin();

        if (leftIdx == 0)
            cout << "X";
        else
            cout << vec[leftIdx - 1];

        cout << " ";

        if (rightIdx == size)
            cout << "X";
        else
            cout << vec[rightIdx];

        cout << endl;
    }
}
int main()
{
    mino;
    solve2();
}

/*
7
1 4 4 5 7 9 10
4
4 6 8 10
*/