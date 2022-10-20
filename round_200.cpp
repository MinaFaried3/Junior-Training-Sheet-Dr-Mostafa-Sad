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

    lol tests;
    cin >> tests;
    string current, previous = "";
    lol count = 1;
    while (tests--)
    {
        cin >> current;
        if (previous == "")
            goto last;

        if (current != previous)
            count++;
    last:
        previous = current;
    }

    cout << count;
}