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
#define PI 3.14159265358979323846
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)
#define mino                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
void solve1()
{
    int count, k;
    cin >> count >> k;

    int counter = 0;
    char limit = k + '0';
    string kGood = "";
    for (char i = '0'; i <= limit; i++)
        kGood += i;

    string num;
    set<char> validation;

    for (int i = 0; i < count; i++)
    {
        validation.clear();
        cin >> num;
        for (int x = 0; x < num.size(); x++)
            validation.insert(num[x]);

        if ((int)validation.size() < (int)kGood.size())
            continue;

        int idx = 0;
        bool valid = true;

        for (char chr : validation)
        {
            if (chr != kGood[idx])
            {
                valid = false;
                break;
            }

            idx++;
            if (idx == kGood.size())
                break;
        }

        counter += valid;
    }

    cout << counter;
}
void solve2()
{
    int count, k;
    cin >> count >> k;

    int counter = 0;
    char limit = k + '0';
    string kGood = "";
    for (char i = '0'; i <= limit; i++)
        kGood += i;

    string num;

    for (int i = 0; i < count; i++)
    {
        cin >> num;
        int digits = 0;

        for (char chr : kGood)
        {
            size_t found = num.find(chr);
            if (found != string::npos)
                digits++;
            else
                break;
        }

        counter += (digits == kGood.size());
    }
    cout << counter;
}
int main()
{
    mino;
    solve2();
}