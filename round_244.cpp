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
struct rook
{
    int x;
    int y;
};
int main()
{
    fast();
    lol tests;
    cin >> tests;
    lol crime = 0, police = 0;
    while (tests--)
    {
        lol num;
        cin >> num;
        if (num != -1)
            police += num;

        if (num == -1 && police == 0)
            crime++;

        if (num == -1 && police != 0)
            police--;
    }

    cout << crime;
}