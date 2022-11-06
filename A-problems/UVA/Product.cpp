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
    string num1, num2;
    while (cin >> num1)
    {
        cin >> num2;

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int result[600]{0};

        for (int i = 0; i < num1.size(); i++)
        {
            for (int j = 0; j < num2.size(); j++)
            {
                result[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        for (int i = 0; i < 600; i++)
        {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }

        int lastIdx = 599;

        while (lastIdx > 0 && result[lastIdx] == 0)
            lastIdx--;

        for (; lastIdx >= 0; lastIdx--)
            cout << result[lastIdx];

        cout << endl;
    }
}