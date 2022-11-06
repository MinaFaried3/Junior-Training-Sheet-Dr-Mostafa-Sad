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
    while (tests--)
    {
        string word;
        cin >> word;

        if (word.size() > 10)
            cout << word[0] << word.size() - 2 << word[word.size() - 1] << endl;
        else
            cout << word << endl;
    }
}