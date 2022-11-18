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
    int step, mod_, index = 0;
    while (cin >> step >> mod_)
    {
        vector<int> visited(mod_, 0);
        bool bad = false;
        for (size_t i = 0; i < mod_; i++)
        {
            int num = (index + step) % mod_;

            if (visited[num] > 0)
            {
                bad = true;
                break;
            }

            visited[num]++;

            index = num;
        }

        cout << setw(10) << step << setw(10) << mod_ << "    ";
        cout << (bad ? "Bad Choice" : "Good Choice") << endl
             << endl;
    }
}