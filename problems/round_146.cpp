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
    set<char> charSet;
    string str;

    cin >> str;
    for (char x : str)
        charSet.insert(x);

    charSet.size() % 2 == 0 ? cout << "CHAT WITH HER!" : cout << "IGNORE HIM!";
}