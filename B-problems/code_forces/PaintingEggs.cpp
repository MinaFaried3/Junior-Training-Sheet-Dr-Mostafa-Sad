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
#define loop(i, n) for (int i = 0; i < n; i++)
#define loopx(n) for (int x = 0; x < n; x++)
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
vector<char> result;

lol eggsNum;

void greedy(lol *A, lol *G, lol idx = 0, lol totalA = 0, lol totalG = 0)
{
    if (idx == eggsNum)
        return;

    if (A[idx] <= G[idx] && abs(totalG - (totalA + A[idx])) <= 500)
    {
        result[idx] = 'A';
        greedy(A, G, idx + 1, totalA + A[idx], totalG);
    }
    else if (G[idx] <= A[idx] && abs(totalA - (totalG + G[idx])) <= 500)
    {
        result[idx] = 'G';
        greedy(A, G, idx + 1, totalA, totalG + G[idx]);
    }
    else if (A[idx] >= G[idx] && abs(totalG - (totalA + A[idx])) <= 500)
    {
        result[idx] = 'A';
        greedy(A, G, idx + 1, totalA + A[idx], totalG);
    }
    else if (G[idx] >= A[idx] && abs(totalA - (totalG + G[idx])) <= 500)
    {
        result[idx] = 'G';
        greedy(A, G, idx + 1, totalA, totalG + G[idx]);
    }
}

int main()
{
    mino;

    cin >> eggsNum;

    result = vector<char>(eggsNum, '*');

    lol *A = new lol[eggsNum];
    lol *G = new lol[eggsNum];

    loop(i, eggsNum)
    {
        cin >> A[i] >> G[i];
    }
    greedy(A, G);

    string res;

    lol totalA = 0, totalG = 0;
    loopSz(result)
    {
        if (result[i] == '*')
        {
            // cout << "*" << endl;
            cout << -1;
            return 0;
        }

        if (result[i] == 'A')
            totalA += A[i];
        else
            totalG += G[i];

        res += result[i];
    }

    if (abs(totalG - totalA) > 500)
    {
        // cout << "abs" << endl;
        cout << -1;
        return 0;
    }

    cout << res;
}