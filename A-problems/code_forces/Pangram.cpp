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
void mino()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    mino();
    int count;
    cin >> count;
    set<char> letters;
    char chr;
    for (size_t i = 0; i < count; i++)
    {
        cin >> chr;
        if (chr < 'a')
            chr += 32;
        letters.insert(chr);
    }

    if ((int)letters.size() < 26)
        cout << "NO";
    else
        cout << "YES";
}