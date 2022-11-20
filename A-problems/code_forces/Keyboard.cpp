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

int main()
{
    mino();
    const string str1{"qwertyuiop"};
    const string str2{"asdfghjkl;"};
    const string str3{"zxcvbnm,./"};

    char direction;
    cin >> direction;
    string word;
    cin >> word;

    int step;
    if (direction == 'R')
        step = -1;
    else
        step = 1;
    int idx;
    for (size_t i = 0; i < word.size(); i++)
    {
        if (str1.find(word[i]) != string::npos)
        {
            idx = str1.find(word[i]) + step;
            cout << str1[idx];
        }
        else if (str2.find(word[i]) != string::npos)
        {
            idx = str2.find(word[i]) + step;
            cout << str2[idx];
        }
        else if (str3.find(word[i]) != string::npos)
        {
            idx = str3.find(word[i]) + step;
            cout << str3[idx];
        }
    }
}