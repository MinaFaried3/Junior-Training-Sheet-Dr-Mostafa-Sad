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

int main()
{
    mino;
    int count;
    cin >> count;
    int chest = 0, biceps = 0, back = 0;
    int chestIdx = 0, bicepsIdx = 1, backIdx = 2;
    for (int i = 0; i < count; i++)
    {
        int exercise;
        cin >> exercise;

        if (i == chestIdx)
        {
            chest += exercise;
            chestIdx += 3;
        }
        else if (i == bicepsIdx)
        {
            biceps += exercise;
            bicepsIdx += 3;
        }
        else if (i == backIdx)
        {
            back += exercise;
            backIdx += 3;
        }
    }

    int maxExercise = max(chest, max(back, biceps));
    if (maxExercise == chest)
        cout << "chest";
    else if (maxExercise == biceps)
        cout << "biceps";
    else if (maxExercise == back)
        cout << "back";
}