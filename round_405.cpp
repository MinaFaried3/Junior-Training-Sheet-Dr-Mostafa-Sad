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
    lol limak, bob;
    cin >> limak >> bob;
    lol years = 0;
    while (!(limak > bob))
    {
        limak *= 3;
        bob *= 2;
        years++;
    }
    // 12 18 36 36

    cout << years;
}