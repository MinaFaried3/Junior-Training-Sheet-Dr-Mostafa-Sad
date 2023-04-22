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

int binary_search(vector<int> arr, int val)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] < val && (mid == arr.size() - 1 || arr[mid + 1] > val))
            return mid;

        if (val > arr[mid])
            start = mid + 1;
        else if (val < arr[mid])
            end = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    mino;
    int rows, cols, wastes_num, query;
    cin >> rows >> cols >> wastes_num >> query;
    vector<int> waste_cells;
    map<int, string> waste_map;
    while (wastes_num--)
    {
        int r, c;
        cin >> r >> c;
        r--, c--;

        int index = r * cols + c;
        waste_cells.push_back(index);
        waste_map[index] = "waste";
    }

    sort(waste_cells.begin(), waste_cells.end());

    while (query--)
    {
        int r, c;
        cin >> r >> c;
        r--, c--;
        int index = r * cols + c;
        if (waste_map[index] == "waste")
        {
            cout << "Waste" << endl;
            continue;
        }
        int prev_waste;
        int final_idx;

        if (index > waste_cells[waste_cells.size() - 1])
        {
            prev_waste = waste_cells.size();
        }
        else
        {
            prev_waste = binary_search(waste_cells, index) + 1;
        }

        final_idx = index - prev_waste;
        switch (final_idx % 3)
        {
        case 0:
            cout << "Carrots";
            break;
        case 1:
            cout << "Kiwis";
            break;
        case 2:
            cout << "Grapes";
            break;
        }

        cout << endl;
    }
}