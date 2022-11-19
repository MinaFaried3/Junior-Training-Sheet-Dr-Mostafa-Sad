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
void solve1()
{
    lol size;
    cin >> size;
    lol *stewards = new lol[size];

    for (lol i = 0; i < size; i++)
    {
        cin >> stewards[i];
    }

    sort(stewards, stewards + size);
    lol count = 0;

    for (lol i = 1; i < size - 1; i++)
    {
        count += (stewards[i] > stewards[0] && stewards[i] < stewards[size - 1]);
    }

    cout << count;
}

void solve2()
{
    mino();
    lol size;
    cin >> size;
    map<lol, lol> stewards;
    lol num;
    for (lol i = 0; i < size; i++)
    {
        cin >> num;
        stewards[num]++;
    }

    map<lol, lol>::iterator itr = stewards.begin();
    itr++;
    lol count = 0;

    for (; itr != prev(stewards.end()); itr++)
    {
        count += itr->second;
    }

    if (stewards.size() > 1)
        cout << count;
    else
        cout << 0;
}
int main()
{
    mino();
    solve2();
}