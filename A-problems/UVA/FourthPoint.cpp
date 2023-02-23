#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

double x[4], y[4];
set<pair<double, double>> st;
set<pair<double, double>>::iterator stit;

void solve1()
{
    freopen("uva.txt", "r", stdin);
    double ax, ay, bx, by, cx, cy;
    while (scanf("%lf%lf", &x[0], &y[0]) != EOF)
    {
        for (int i = 1; i < 4; i++)
            scanf("%lf%lf", &x[i], &y[i]); // read 4 points
        st.clear();
        for (int i = 0; i < 4; i++)
        { // find common 2 point and put other 2 in st
            if (st.find({x[i], y[i]}) != st.end())
            {                           // if this point already exist in st, this the common point
                st.erase({x[i], y[i]}); // we don't want this common point in st
                cx = x[i], cy = y[i];
            }
            else
                st.insert({x[i], y[i]});
        }
        stit = st.begin();                   // get other 2 points from st
        ax = stit->first, ay = stit->second; // first point
        stit++;
        bx = stit->first, by = stit->second;                 // second point
        printf("%.3lf %.3lf\n", ax + bx - cx, ay + by - cy); // fourth point is just (a+b-c) because c is added twice in a and b
    }
}

void solve2()
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf",
                 &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4) == 8)
    {
        if (x1 == x3 && y1 == y3)
            printf("%.3lf %.3lf\n", (x2 + x4) - x1, (y2 + y4) - y1);
        else if (x1 == x4 && y1 == y4)
            printf("%.3lf %.3lf\n", (x2 + x3) - x1, (y2 + y3) - y1);
        else if (x2 == x3 && y2 == y3)
            printf("%.3lf %.3lf\n", (x1 + x4) - x2, (y1 + y4) - y2);
        else
            printf("%.3lf %.3lf\n", (x1 + x3) - x2, (y1 + y3) - y2);
    }
}
int main()
{
    solve2();
}