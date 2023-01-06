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
#define LABEL(i, title) cout << " " << i << " - " << title << " :-" << endl
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)

void mino()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void tokenize(string s, string del = " ")
{
    int start, end = -1 * del.size();
    do
    {
        start = end + del.size();
        end = s.find(del, start);
        cout << s.substr(start, end - start) << " ";
    } while (end != -1);
}
int main()
{
    mino();

    const string wub = "WUB";

    string song;
    cin >> song;
    bool printWord = false;
    for (int i = 0; i < song.size(); i++)
    {
        if (song[i] == 'W' && song[i + 1] == 'U' && song[i + 2] == 'B')
        {
            i += 2;
            if (printWord)
            {
                cout << ' ';
                printWord = false;
            }

            continue;
        }

        cout << song[i];
        printWord = true;
    }


}