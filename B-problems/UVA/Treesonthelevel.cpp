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
#define sz(v) ((lol)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define loop(i, n) for (int i = 0; i < n; i++)
#define loopx(n) for (int x = 0; x < n; x++)
#define loopR(x, n) for (int i = x; i <= (int)(n); ++i)
#define loopSz(v) for (int i = 0; i < sz(v); ++i)
#define loopItr(structure) for (auto itr = structure.begin(); itr != structure.end(); itr++)
#define loopItr1(structure) for (auto setItr = structure.begin(); setItr != structure.end(); setItr++)
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
pair<string, int> getPair(string str)
{
    int num = 0;
    string direction = "*";
    int i;
    for (i = 1; i < sz(str) && str[i] != ','; i++)
    {
        num *= 10;
        num += (str[i] - '0');
    }

    i++;
    for (; i < sz(str) && str[i] != ')'; i++)
    {
        direction += str[i];
    }

    // cout << num << " " << direction << endl;

    return make_pair(direction, num);
}
int main()
{
    mino;
    string node;
    map<int, set<pair<string, int>>> tree;
    map<int, set<string>> treeStr;
    while (cin >> node)
    {
        if (node == "()")
        {
            bool valid = true;
            vector<int> vec;
            // output
            loopItr(tree)
            {
                set<pair<string, int>> st = itr->second;
                if (!valid)
                    break;

                if (sz(st))
                {
                    loopItr1(st)
                    {
                        if (itr->first == 1)
                        {
                            if (sz(st) > 1)
                            {
                                valid = false;
                                break;
                            }

                            vec.push_back(setItr->second);
                            continue;
                        }

                        string currStr = setItr->first;
                        currStr.pop_back();

                        // cout << "after delete = " << currStr << endl;
                        if (treeStr[itr->first - 1].find(currStr) != treeStr[itr->first - 1].end())
                        {
                            vec.push_back(setItr->second);
                        }
                        else
                        {
                            valid = false;
                            break;
                        }
                    }
                }
            }

            if (valid)
            {
                for (int num : vec)
                    cout << num << " ";
            }
            else
            {
                cout << "not complete";
            }
            cout << endl;

            // reset
            tree.clear();
            treeStr.clear();
            continue;
        }

        pair<string, int> currPair = getPair(node);
        tree[currPair.first.size()].insert(currPair);
        treeStr[currPair.first.size()].insert(currPair.first);
    }
}