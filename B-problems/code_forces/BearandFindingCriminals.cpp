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

void solve1()
{
    int size, my_city;
    cin >> size >> my_city;
    my_city--;

    int *criminals = new int[size];
    int *visited = new int[size]{0};
    vector<int> distance;
    char f = CHAR_MAX;
    for (int i = 0; i < size; i++)
    {
        cin >> criminals[i];

        if (criminals[i])
            distance.push_back(abs(my_city - i));
    }

    int count = 0;

    for (int i = 0; i < distance.size(); i++)
    {

        int left = my_city - distance[i];
        int right = my_city + distance[i];

        if (distance[i] == 0 && !visited[left])
        {
            count++;
            visited[left] = true;
        }
        else if (left >= 0 && right >= size && !visited[left])
        {
            count++;
            visited[left] = true;
        }
        else if (left < 0 && right < size && !visited[right])
        {
            count++;
            visited[right] = true;
        }
        else if (left >= 0 &&
                 right < size &&
                 criminals[left] &&
                 criminals[right] &&
                 !visited[left] &&
                 !visited[right])
        {
            count += 2;
            visited[left] = true;
            visited[right] = true;
        }
    }

    cout << count << endl;
}

void solve2()
{

    int distance, numOFcity, pos, sum = 0;
    cin >> numOFcity >> pos;

    vector<int> arr(numOFcity + 1);

    for (distance = 1; distance <= numOFcity; distance++)
    {
        cin >> arr[distance];
        sum += arr[distance];
    }

    for (distance = 1; distance < pos && distance <= numOFcity - pos; distance++)
    {
        if (arr[pos + distance] + arr[pos - distance] == 1)
            sum--;
    }

    cout << sum;
}
int main()
{
    mino;
    solve2();
}