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
void solution1()
{
    int count;
    cin >> count;
    map<int, int> friends;
    int num;
    for (size_t i = 1; i <= count; i++)
    {
        cin >> num;
        friends[num] = i;
    }

    map<int, int>::iterator itr;
    for (itr = friends.begin(); itr != friends.end(); itr++)
    {
        cout << itr->second << " ";
    }
}
void solution2()
{
    int count;
    cin >> count;

    int *friends = new int[count];
    int num;
    for (size_t i = 0; i < count; i++)
    {
        cin >> num;
        friends[num] = i + 1;
    }

    for (size_t i = 0; i < count; i++)
    {
        cout << friends[i + 1] << " ";
    }
}
int main()
{
    mino();
    solution2();
}