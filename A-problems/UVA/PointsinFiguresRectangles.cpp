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
struct Point
{
    double x;
    double y;

    void print(string name)
    {
        cout << name << ".x = " << x << endl;
        cout << name << ".y = " << y << endl;
    }
};

struct Rectangle
{
    Point upLeft;
    Point upRight;
    Point downLeft;
    Point downRight;

    double left, right, down, up;

    Rectangle(double xUp, double yUp, double xDown, double yDown)
    {

        left = xUp;
        right = xDown;
        up = yUp;
        down = yDown;

        upLeft.x = xUp;
        upLeft.y = yUp;

        downRight.x = xDown;
        downRight.y = yDown;

        downLeft.x = xUp;
        downLeft.y = yDown;

        upRight.x = xDown;
        upRight.y = yUp;
    }

    void print()
    {
        upLeft.print("upLeft");
        upRight.print("upRight");
        downLeft.print("downLeft");
        downRight.print("downRight");
    }
};

int main()
{
    mino();
    vector<Rectangle> rectangles;
    char chr;
    while (cin >> chr && chr != '*')
    {
        double xUp, yUp, xDown, yDown;
        cin >> xUp >> yUp >> xDown >> yDown;

        rectangles.push_back(Rectangle(xUp, yUp, xDown, yDown));
    }

    double x, y;
    int pointOrder = 0;
    while (cin >> x >> y && x != 9999.9 && y != 9999.9)
    {
        pointOrder++;
        bool founded = false;
        for (int i = 0; i < rectangles.size(); i++)
        {
            Rectangle rec = rectangles[i];
            if (x > rec.left && x < rec.right && y > rec.down && y < rec.up)
            {
                cout << "Point " << pointOrder << " is contained in figure " << i + 1 << endl;
                founded = true;
            }
        }
        if (!founded)
        {
            cout << "Point " << pointOrder << " is not contained in any figure" << endl;
        }
    }
}