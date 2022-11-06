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

    string str;
    cin >> str;
  //! Think like circle perimeter 
  /**
   * if length between two points less than 13 that means this part is less than circle perimeter (26) 
   * else if more than 26
   * we will take the another part of circle we calculate it in (26-current length)
   * 
   */
    int count = 0;
    int start = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        int index = str[i] - 97; //25
        int movement = abs(start - index);//25

        if (movement < 13)
            count += movement;
        else
            count += 26 - movement;

        start = index;
    }

    cout << count;
}