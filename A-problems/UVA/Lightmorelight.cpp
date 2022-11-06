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
#define unint unsigned int
#define endl '\n'
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fast();

    unint num;

    while (cin >> num && num != 0)
    {
        unint sqt = sqrt(num);

        cout << (sqt * sqt == num ? "yes" : "no") << endl;
    }
}