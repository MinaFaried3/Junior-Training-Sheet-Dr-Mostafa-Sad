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

    int size;
    cin >> size;
    string str;
    cin >> str;
    int count = 0;

    for (size_t i = 1; i < size; i++)
    {

        if (str[i] == str[i - 1])
            count++;
    }

    cout << count;
}
