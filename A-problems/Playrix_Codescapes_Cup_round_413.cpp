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
#include <set>
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
    double wantedCakes, cakesTime, cakes, builtTime;
    //         8            6         4        5
    //         10           3         11       4

    cin >> wantedCakes >> cakesTime >> cakes >> builtTime;

    // int periods = ceil(wantedCakes / cakes);
    int periods = (wantedCakes + cakes - 1) / cakes;

    int withOutOven = periods * cakesTime;
    int withOven = cakesTime + builtTime;

    bool needed = false;
    if (cakes < wantedCakes)
    {
        if (withOutOven > withOven)
            needed = true;
    }

    needed ? cout << "YES" : cout << "NO";
}