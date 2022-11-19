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
    string str1, str2;
    cin >> str1 >> str2;

    if (str1.size() != str2.size())
    {
        cout << max(str1.size(), str2.size());
    }
    else
    {
        if (str1 == str2)
            cout << -1;
        else
            cout << str1.size();
    }
}