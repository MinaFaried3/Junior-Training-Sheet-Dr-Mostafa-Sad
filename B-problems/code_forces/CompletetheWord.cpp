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
#define loop(n) for (int i = 0; i < n; i++)
#define loopx(n) for (int x = 0; x < n; x++)
#define loopR(x, n) for (int i = x; i <= (int)(n); ++i)
#define loopSz(v) for (int i = 0; i < sz(v); ++i)
#define loopItr(structure) for (auto itr = structure.begin(); itr != structure.end(); itr++)
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

int main()
{
    mino;

    const string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string word;
    cin >> word;

    if (sz(word) < 26)
    {
        cout << -1;
        return 0;
    }

    bool valid = false;

    for (int i = 0; i <= sz(word) - 26 && valid == false; i++)
    {
        int question_marks = 0, founded = 0;
        map<char, bool> visited;
       
        string str = "";

        for (int x = i; x < i + 26; x++)
        {
            str += word[x];
          
        
            if (word[x] == '?')
            {
               
                question_marks++;
                continue;
            }

            visited[word[x]] = true;
        }

      

        if (sz(visited) + question_marks == 26)
        {
            valid = true;
            queue<char> missed_letters;
            // todo count missed and break;
            for (int x = 0; x < 26; x++)
            {
                if (visited[letters[x]] == false)
                {
                    missed_letters.push(letters[x]);
                   
                }
            }

            for (int x = 0; x < 26; x++)
            {
                if (str[x] == '?')
                {
                    str[x] = missed_letters.front();
                    missed_letters.pop();
                   
                }
            }

            for (int x = i; x < i + 26; x++)
            {
                word[x] = str[x - i];
            }
          

            loopx(sz(word))
            {
                if (word[x] == '?')
                    word[x] = 'A';
            }
        }
    }

    valid ? cout << word : cout << -1;
}
/*
A?BCDEFGHIJKLMNOPQRSTUVWXYZ
*/