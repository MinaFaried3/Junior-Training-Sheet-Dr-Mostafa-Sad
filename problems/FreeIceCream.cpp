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
    int tests;
    cin >> tests;
    lol mainPacks, distressedKids = 0;
    cin >> mainPacks;

    while (tests--)
    {
        char role;
        lol packs;

        cin >> role >> packs;

        if (role == '+')
            mainPacks += packs;
        else
        {
            if (mainPacks >= packs)
                mainPacks -= packs;
            else
                distressedKids++;
        }
    }

    cout << mainPacks << " " << distressedKids;
}