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
    int tests;
    cin >> tests;

    while (tests--)
    {
        int boards, rooks;
        cin >> boards >> rooks;

        rook *arr = new rook[rooks];

        for (int i = 0; i < rooks; i++)
        {
            cin >> arr[i].x;
            cin >> arr[i].y;
        }

        rooks < boards ? cout << "YES" << endl : cout << "NO" << endl;
    }
}