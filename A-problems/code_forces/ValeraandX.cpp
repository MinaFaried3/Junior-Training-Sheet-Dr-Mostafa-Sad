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

bool isPalindrome(string str)
{
    for (int i = 0; i <= str.size() / 2; i++)
    {
        if (str[i] != str[str.size() - 1 - i])
            return false;
    }
    return true;
}
int main()
{
    mino();
    int size;
    cin >> size;
    string *arr = new string[size];
    set<char> characters;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];

        string str = arr[i];
        for (int i = 0; i <= str.size() / 2; i++)
        {
            characters.insert(str[i]);
            characters.insert(str[str.size() - 1 - i]);
        }
    }

    char x = arr[0][0];

    if (characters.size() != 2)
    {
        cout << "NO";
        return 0;
    }

    for (int i = 0; i <= size / 2; i++)
    {
        if (
            !isPalindrome(arr[i]) ||
            arr[i] != arr[size - 1 - i] ||
            arr[i][i] != x ||
            arr[i][size - 1 - i] != x)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}
/*
5
xooox
xooox
xooox
xooox
xooox

5
xooox
oxoxo
ooxoo
oxoxo
xooox

5
xooox
oxoxo
soxos
oxoxo
xooox

3
xpx
pxp
xpx
*/