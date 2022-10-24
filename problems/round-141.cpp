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
    map<lol, int> hoursShoes;
    int count = 0;
    for (size_t i = 1; i <= 4; i++)
    {
        lol num;
        cin >> num;
        if (hoursShoes[num] == 0)
            hoursShoes[num]++;
        else
            count++;
    }
    cout << count << endl;
}