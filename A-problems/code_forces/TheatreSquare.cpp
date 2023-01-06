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

int main()
{
    mino();

    lol width, length, stone;
    cin >> width >> length >> stone;
    lol result = 0;

    if (width > length)
        swap(width, length);

    if (stone >= width && stone >= length)
        result = 1;
    else
    {
        lol vertical, horizontal;

        if (length % stone == 0)
            horizontal = length / stone;
        else
            horizontal = (length / stone) + 1;

        if (width % stone == 0)
            vertical = width / stone;
        else
            vertical = (width / stone) + 1;

        result = horizontal * vertical;
    }
    cout << result;
}