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

    int *wires = new int[size];

    for (size_t i = 0; i < size; i++)
    {
        cin >> wires[i];
    }

    int shotsNumber;
    cin >> shotsNumber;

    int wireIndex, birdIndex;
    while (shotsNumber--)
    {
        cin >> wireIndex >> birdIndex;
        wireIndex--;
    
        int leftBirds = birdIndex - 1;
        int rightBirds = wires[wireIndex] - birdIndex;
        wires[wireIndex] = 0;

        if (wireIndex != 0)
            wires[wireIndex - 1] += leftBirds;

        if (wireIndex != size - 1)
            wires[wireIndex + 1] += rightBirds;
    }

    for (size_t i = 0; i < size; i++)
    {
        cout << wires[i] << endl;
    }
}