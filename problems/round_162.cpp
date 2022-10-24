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
    string stones, instruction;
    int index = 0, position = 0;
    cin >> stones >> instruction;
    for (size_t i = 0; i < instruction.size(); i++)
    {
        if (instruction[i] == stones[index])
        {
            position++;
            index++;
        }
    }
    position++;
    cout << position << endl;
}