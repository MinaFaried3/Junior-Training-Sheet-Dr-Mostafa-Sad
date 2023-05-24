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
bool automaton(string str, string wanted)
{
    if (wanted.size() > str.size())
        return false;

    int idx = 0;
    for (int i = 0; i < str.size(); i++)
    {
        idx = 0;
        if (str[i] == wanted[idx])
        {
            for (int j = i; j < str.size(); j++)
            {
                if (str[j] == wanted[idx])
                    idx++;
            }
        }

        if (idx == wanted.size())
        {
            return true;
        }
    }

    return false;
}

bool isArray(string str, string wanted)
{
    if (wanted.size() != str.size())
        return false;

    sort(all(str));
    sort(all(wanted));

    return str == wanted;
}
bool both(string str, string wanted)
{
    if (wanted.size() > str.size())
        return false;

    int freqStr[128]{0}, freqWanted[128]{0};

    for (int i = 0; i < str.size(); i++)
    {
        if (i < wanted.size())
        {
            freqWanted[wanted[i]]++;
        }

        freqStr[str[i]]++;
    }

    for (int i = 0; i < 128; i++)
    {
        if (freqStr[i] < freqWanted[i])
            return false;
    }

    return true;
}
int main()
{
    mino;
    string str, wanted;
    cin >> str >> wanted;

    if (automaton(str, wanted))
    {
        cout << "automaton";
        return 0;
    }

    if (isArray(str, wanted))
    {
        cout << "array";
        return 0;
    }
    if (both(str, wanted))
    {
        cout << "both";
        return 0;
    }
    cout << "need tree";
}