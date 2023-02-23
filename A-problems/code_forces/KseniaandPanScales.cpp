#include <set>
#include <map>
#include <list>
#include <iomanip>
#include <cmath>
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
#define mino                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void solve1()
{
    string scale, weights;
    cin >> scale >> weights;

    string rightWeight = "", leftWeight = "";
    bool isLeft = true;

    for (int i = 0; i < scale.size(); i++)
    {
        if (scale[i] == '|')
        {
            isLeft = false;
            continue;
        }

        if (isLeft)
            leftWeight += scale[i];

        else
            rightWeight += scale[i];
    }

    int rightSize = rightWeight.size();
    int leftSize = leftWeight.size();
    int weightsSize = weights.size();

    bool change = false;

    int totalSize = rightSize + weightsSize + leftSize;
    if (totalSize % 2 == 0)
    {
        change = true;
        int sideSize = totalSize / 2;

        for (int i = 0; i < weightsSize; i++)
        {
            if (leftWeight.size() < sideSize)
                leftWeight += weights[i];
            else
                rightWeight += weights[i];
        }
    }

    if (rightWeight.size() == leftWeight.size() && change)
        cout << leftWeight << "|" << rightWeight;
    else
        cout << "Impossible";
}

void solve2()
{
    string scale, weights;
    cin >> scale >> weights;

    int middle = scale.find('|');
    string left = scale.substr(0, middle);
    string right = scale.substr(middle + 1);

    for (char chr : weights)
        if (left.size() < right.size())
            left += chr;
        else
            right += chr;

    if (left.size() == right.size())
        cout << left << "|" << right;
    else
        cout << "Impossible";
}
int main()
{
    mino;
    solve2();
}