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
lol gcd(lol a, lol b)
{
    return b == 0 ? a : gcd(b, a % b);
}
lol lcm(lol a, lol b) { return a / gcd(a, b) * b; }
void count_bear_substr()
{
    mino;
    string str;
    cin >> str;
    lol result = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        lol bearCount = 0;
        lol bearIdx = -1;
        bool increment = false;
        for (int x = i; x < str.size(); x++)
        {
            if (x <= str.size() - 4 && str[x] == 'b' && str[x + 1] == 'e' && str[x + 2] == 'a' && str[x + 3] == 'r')
            {
                bearIdx = x + 3;
            }

            if (bearIdx == x)
            {
                bearCount++;
                // cout << x << " " << bearCount << endl;
                increment = true;
            }

            if (increment)
                result += bearCount;
        }
    }
    cout << result;
}

void solve1()
{
    string str;
    vector<int> bearIdx;
    cin >> str;
    long long size = str.size(), beforChr = 1, afterChr, ans = 0;
    for (int i = 0; i + 3 < size; i++)
        if (str[i] == 'b' && str[i + 1] == 'e' && str[i + 2] == 'a' && str[i + 3] == 'r')
            bearIdx.push_back(i + 1);
    
    for (int i = 0; i < bearIdx.size(); i++)
    {
        afterChr = size - bearIdx[i] - 2; 
      
        if (i)
            beforChr = bearIdx[i - 1] + 1; 

        beforChr = bearIdx[i] - beforChr + 1;
      
        ans += (beforChr * afterChr);
    }
    cout << ans << endl;
}
int main()
{
    mino;
    string str;
    cin >> str;
    lol result = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        lol bearIdx = -1;
        bool increment = false;
        for (int x = i; x < str.size(); x++)
        {
            if (x <= str.size() - 4 && str[x] == 'b' && str[x + 1] == 'e' && str[x + 2] == 'a' && str[x + 3] == 'r')
            {
                bearIdx = x + 3;
            }

            if (bearIdx == x)
            {
                increment = true;
            }

            if (increment)
            {
                result++;
            }
        }
    }
    cout << result;
}
