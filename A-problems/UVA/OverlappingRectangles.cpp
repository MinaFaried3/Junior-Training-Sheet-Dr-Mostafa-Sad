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

int main()
{
    mino();

    lol cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {

        int xl1, yl1, xu1, yu1;
        int xl2, yl2, xu2, yu2;
        cin >> xl1 >> yl1 >> xu1 >> yu1;
        cin >> xl2 >> yl2 >> xu2 >> yu2;
        
        if (i > 0)
            cout << endl;

        if (max(xl1, xl2) < min(xu1, xu2) && max(yl1, yl2) < min(yu1, yu2))
            cout << max(xl1, xl2) << " " << max(yl1, yl2) << ' ' << min(xu1, xu2) << ' ' << min(yu1, yu2) << endl;
        else
            cout << "No Overlap" << endl;
    }
}