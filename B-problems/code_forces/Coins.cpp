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

map<char, int> mp;
void bigger_char(string str)
{
    if (str[1] == '<')
        mp[str[2]]++;
    else
        mp[str[0]]++;
}
int main()
{
    mino;
    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;

    mp.insert(make_pair('A', 0));
    mp.insert(make_pair('B', 0));
    mp.insert(make_pair('C', 0));

    bigger_char(str1);
    bigger_char(str2);
    bigger_char(str3);

    char big = '0', mid = '0', small = '0';

    map<char, int>::iterator itr;
    for (itr = mp.begin(); itr != mp.end(); itr++)
    {
        if (itr->second == 2)
            big = itr->first;
        else if (itr->second == 1)
            mid = itr->first;
        else if (itr->second == 0)
            small = itr->first;
    }

    if (big == '0' || mid == '0' || small == '0')
        cout << "Impossible";
    else
        cout << small << mid << big;
}