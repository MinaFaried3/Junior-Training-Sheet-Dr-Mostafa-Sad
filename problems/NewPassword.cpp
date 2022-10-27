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
char arr[26]{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int main()
{
    fast();

    int length, distinct;
    cin >> length >>distinct;

    int times = length / distinct;
    int needed = length % distinct;

    for (int i = 0; i < times; i++)
        for (int i = 0; i < distinct; i++)
            cout << arr[i];

    for (int i = 0; i < needed; i++)
        cout << arr[i];
}