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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.sync_with_stdio(0);
}
lol gcd(lol a, lol b)
{
    if (a == 0)
        return b;
    gcd(b % a, a);
}
lol lcm(lol a, lol b)
{
    return (a * b) / gcd(a, b);
}
int arr[4];
lol go(int id, int cnt, lol me, lol upto)
{
    if (id == 5)
    {
        if (cnt % 2)
            return -me / upto;
        else
            return me / upto;
    }
    lol ret = 0;
    ret += go(id + 1, cnt + 1, me, lcm(upto, arr[id]));
    ret += go(id + 1, cnt, me, upto);
    return ret;
}
int main()
{
    fast();
    int tests;
    cin >> tests;
    while (tests--)
    {
        lol start, end, a, d;
        cin >> start >> end >> a >> d;

        arr[0] = a;
        arr[1] = a + d;
        arr[2] = a + (2 * d);
        arr[3] = a + (3 * d);
        arr[4] = a + (4 * d);

        cout << go(0, 0, end, 1) - go(0, 0, start - 1, 1) << endl;
    }
}