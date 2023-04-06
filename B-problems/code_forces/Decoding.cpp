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

int main()
{
    mino;
    lol count;
    cin >> count;

    string word;
    cin >> word;

    list<char> encode;
    encode.push_back(word[0]);

    for (int i = 1; i < count; i++)
    {
        if (count % 2 == 0)
            if (i % 2 == 0)
                encode.push_front(word[i]);

            else
                encode.push_back(word[i]);

        if (count % 2 != 0)
            if (i % 2 == 0)
                encode.push_back(word[i]);
            else
                encode.push_front(word[i]);
    }

    list<char>::iterator itr;
    for (itr = encode.begin(); itr != encode.end(); itr++)
    {
        cout << *itr;
    }
}