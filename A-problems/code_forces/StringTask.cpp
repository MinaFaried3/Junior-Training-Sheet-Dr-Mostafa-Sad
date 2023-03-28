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
    string word;
    cin >> word;
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == 'A' ||
            word[i] == 'O' ||
            word[i] == 'Y' ||
            word[i] == 'E' ||
            word[i] == 'U' ||
            word[i] == 'I' ||
            word[i] == 'a' ||
            word[i] == 'o' ||
            word[i] == 'y' ||
            word[i] == 'e' ||
            word[i] == 'u' ||
            word[i] == 'i')
            continue;

        if (word[i] < 'a')
            word[i] += 32;

        cout << '.' << word[i];
    }
}