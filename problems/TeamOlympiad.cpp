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

int main()
{
    fast();
    vector<int> programming, maths, pe;

    int size;
    cin >> size;
    int type, index = 0;
    while (size--)
    {
        cin >> type;
        index++;
        switch (type)
        {
        case 1:
            programming.push_back(index);
            break;
        case 2:
            maths.push_back(index);
            break;
        case 3:
            pe.push_back(index);
            break;
        }
    }

    int teamNum = min(programming.size(), min(maths.size(), pe.size()));

    cout << teamNum << endl;

    if (teamNum > 0)
        for (size_t i = 0; i < teamNum; i++)
        {
            cout << programming[i] << ' ' << maths[i] << ' ' << pe[i] << endl;
        }
}