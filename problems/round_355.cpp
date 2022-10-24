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
using namespace std;
#define lol long long int
#define endl '\n'
void fast()
{
    cin.tie(0);
    cout.sync_with_stdio(0);
}

int main()
{
    fast();
    int size, height;
    cin >> size >> height;
    int *arr = new int[size];
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];

        if (arr[i] <= height)
            sum++;
        else
            sum += 2;
    }

    cout << sum << endl;
}