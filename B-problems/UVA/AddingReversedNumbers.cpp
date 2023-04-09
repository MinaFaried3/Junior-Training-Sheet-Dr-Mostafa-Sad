#include <set>
#include <map>
#include <array>
#include <list>
#include <iomanip>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <assert.h>
#include <memory.h>
#include <bitset>
using namespace std;

#define lol long long int
#define endl '\n'
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define loop0(n) for (int i = 0; i < n; i++)
#define loop1(n) for (int i = 1; i <= n; i++)
#define loop(i, n) for (int i = 0; i < (int)(n); ++i)
#define loopSz(i, v) for (int i = 0; i < sz(v); ++i)
#define BREAK cout << "--------------------------------------------------------------------" << endl
int numIDX = 0;
#define LABEL(title) cout << endl                                        \
                          << ++numIDX << " - " << title << " :-" << endl \
                          << endl;
#define PI 3.14159265358979323846
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)
#define sizeOf(arr) sizeof(arr) / sizeof(arr[0])
#define mino                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
lol gcd(lol a, lol b)
{
    return b == 0 ? a : gcd(b, a % b);
}
lol lcm(lol a, lol b) { return a / gcd(a, b) * b; }
string reverse_num(string num)
{
    string rev_num = "";
    bool valid = false;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        if (num[i] != '0' && !valid)
            valid = true;

        if (valid)
        {
            rev_num += num[i];
        }
    }

    return rev_num;
}

string sum(string n1, string n2)
{
    string result = "";
    int carry = 0;

    if (n2.size() > n1.size())
        swap(n1, n2);

    string rev1 = reverse_num(n1);
    string rev2 = reverse_num(n2);
    int num;
    for (int i = 0; i < rev1.size(); i++)
    {
        if (i < rev2.size())
        {
            num = (rev1[i] - '0') + (rev2[i] - '0');
        }
        else
        {
            num = (rev1[i] - '0');
        }

        num += carry;

        int digit = num % 10;

        result += (char)(digit + '0');

        carry = num / 10;
    }

    while (carry)
    {
        int digit = carry % 10;

        result += (char)(digit + '0');

        carry /= 10;
    }

    return result;
}

string remove0(string num)
{
    string result = "";
    bool valid = false;
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] != '0' && !valid)
            valid = true;

        if (valid)
        {
            result += num[i];
        }
    }

    return result;
}

int main()
{
    mino;
    lol cases;
    cin >> cases;
    while (cases--)
    {
        string n1, n2;
        cin >> n1 >> n2;
        string rev1 = reverse_num(n1);
        string rev2 = reverse_num(n2);

        string sum_n = sum(rev1, rev2);

        cout << remove0(sum_n) << endl;
        // cout << rev1<< endl;
        // cout << rev2 << endl;
    }
}

/*
4
1002000
123400
40305070000
2430043043
1002000
123400
40305070000
2430043043
*/