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

    int size;
    cin >> size;

    int start = 0, end = size - 1;

    int *arr = new int[size];

    for (size_t i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    lol left = 0, right = 0;

    bool isLeft = true;

    for (size_t i = 0; i < size; i++)
    {
        if (isLeft)
        {
            if (arr[start] >= arr[end])
            {
                left += arr[start];
                start++;
            }
            else
            {
                left += arr[end];
                end--;
            }
        }
        else
        {
            if (arr[start] >= arr[end])
            {
                right += arr[start];
                start++;
            }
            else
            {
                right += arr[end];
                end--;
            }
        }

        isLeft = !isLeft;
    }

    cout << left << " " << right << endl;
}

/*
 7 1
 13
*/