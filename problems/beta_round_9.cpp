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
int findDivision(int allWays, int dotWays)
{
    for (size_t i = dotWays; i >= 2; i--)
    {
        if (dotWays % i == 0 && allWays % i == 0)
            return i;
    }
    return -1;
}
void solution1()
{
    int yakko, wakko;
    cin >> yakko >> wakko;

    int max_ = max(yakko, wakko);

    int allWays = 6;
    int dotWays = allWays - max_ + 1;

    if (dotWays == 6)
        cout << "1/1";
    else
    {
        int divisionPart = findDivision(allWays, dotWays);
        if (divisionPart == -1)
            cout << dotWays << "/" << allWays;
        else
            cout << dotWays / divisionPart << "/" << allWays / divisionPart;
    }
}

void solution2()
{
    int yakko, wakko;
    cin >> yakko >> wakko;

    int max_ = max(yakko, wakko);

    string dieResults[]{"1/6", "1/3", "1/2", "2/3", "5/6", "1/1"};

    cout << dieResults[6 - max_];
}
int main()
{
    fast();

    solution2();
}