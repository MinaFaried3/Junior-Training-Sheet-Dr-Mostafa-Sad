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

    vector<char> vec;

    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] != '+')
            vec.push_back(str[i]);
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];

        if (vec.size() >= 1 && i != vec.size() - 1)
            cout << '+';
    }
}