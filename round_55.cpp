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

    string str;
    cin >> str;

    int upper = 0, lower = 0;

    for (char x : str)
        if (x < 'a')
            upper++;
        else
            lower++;

    if (upper > lower)
    {
        for (char &x : str)
            if (x >= 'a')
                x -= 32;
    }
    else
        for (char &x : str)
            if (x < 'a')
                x += 32;

    cout << str;
}