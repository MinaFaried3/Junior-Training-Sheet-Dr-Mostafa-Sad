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
    lol a = 0, d = 0;
    lol size;
    cin >> size;
    char chr;

    for (lol i = 0; i < size; i++)
    {
        cin >> chr;

        if (chr == 'A')
            a++;
        else
            d++;
    }

    if (a > d)
        cout << "Anton";
    else if (a < d)
        cout << "Danik";
    else
        cout << "Friendship";
}