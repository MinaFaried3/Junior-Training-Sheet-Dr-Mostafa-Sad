#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <tuple>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define lol long long int
#define endl '\n'
void fast()
{
    cin.tie(0);
    cout.sync_with_stdio(0);
}

int main()
{
    fast();
    int problems;
    cin >> problems;
    int sol = 0;
    while (problems--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        sol += (x+y+z >= 2);
    }

    cout << sol << endl;
}