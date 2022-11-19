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
lol findCost(lol num1, lol num2)
{
    lol result;
    if ((num1 <= 0 && num2 <= 0) || (num1 >= 0 && num2 >= 0))
        result = abs(abs(num1) - abs(num2));
    else
        result = abs(abs(num1) + abs(num2));
    return result;
}
int main()
{
    mino();
    int count;
    cin >> count;
    lol *cities = new lol[count];
    for (int i = 0; i < count; i++)
    {
        cin >> cities[i];
    }
    lol min_, max_;
    for (int i = 0; i < count; i++)
    {
        if (i == 0)
        {
            min_ = findCost(cities[0], cities[1]);
            max_ = findCost(cities[0], cities[count - 1]);
        }
        else if (i == count - 1)
        {
            min_ = findCost(cities[i], cities[i - 1]);
            max_ = findCost(cities[i], cities[0]);
        }
        else
        {
            min_ = min(findCost(cities[i], cities[i - 1]), findCost(cities[i], cities[i + 1]));
            max_ = max(findCost(cities[i], cities[0]), findCost(cities[i], cities[count - 1]));
        }

        cout << min_ << " " << max_ << endl;
    }
}