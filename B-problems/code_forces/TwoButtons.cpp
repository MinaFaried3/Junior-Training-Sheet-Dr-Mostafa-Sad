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

int main()
{
    mino;
    lol init, wanted;
    cin >> init >> wanted;
    if (init > wanted)
    {
        cout << init - wanted << endl;
        return 0;
    }

    queue<pair<int, int>> que;
    int degree = 0;

    que.push({init, degree});
    bool visited[20004]{0};

    while (!que.empty())
    {
        int curr = que.front().first;
        int curr_degree = que.front().second;
        visited[curr] = true;
        if (curr == wanted)
        {
            cout << curr_degree << endl;
            return 0;
        }
        que.pop();

        if (curr - 1 >= 0 && !visited[curr - 1])
            que.push({curr - 1, curr_degree + 1});
            
        if (curr * 2 <= 20000 && !visited[curr * 2])
            que.push({curr * 2, curr_degree + 1});
    }
}