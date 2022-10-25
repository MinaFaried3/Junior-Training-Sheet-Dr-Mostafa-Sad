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
void solve1()
{
    string str;
    getline(cin, str);
    set<char> charSet;

    for (char chr : str)
    {

        if (chr >= 'a' && chr <= 'z')
            charSet.insert(chr);
    }

    cout << charSet.size() << endl;
}
void solve2()
{
    char chr;
    set<char> charSet;
    while (cin >> chr)
    {

        if (chr >= 'a' && chr <= 'z')
            charSet.insert(chr);
    }

    cout << charSet.size() << endl;
}
int main()
{
    fast();
    solve2();
}