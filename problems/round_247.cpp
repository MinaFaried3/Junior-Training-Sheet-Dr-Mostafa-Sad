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

    int arr[5];

    cin >> arr[1];
    cin >> arr[2];
    cin >> arr[3];
    cin >> arr[4];

    string str;
    cin >> str;
    lol calories = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        int num = str[i] - '0';

        calories += arr[num];
    }

    cout << calories;
}