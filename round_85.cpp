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
    string str1, str2;
    cin >> str1 >> str2;

    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] == str2[i] || str1[i] == str2[i] + 32 || str2[i] == str1[i] + 32)
            continue;

        if (str1[i] < 97)
            str1[i] += 32;
        if (str2[i] < 97)
            str2[i] += 32;
        
        if (str1[i] > str2[i])
        {
            cout << 1;
            return 0;
        }
        else
        {
            cout << -1;
            return 0;
        }
    }

    cout << 0;
}