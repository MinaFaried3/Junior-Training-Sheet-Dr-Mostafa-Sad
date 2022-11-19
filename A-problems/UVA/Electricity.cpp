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
void mino()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int monthsDay[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isConsecutive(int preDay, int preMonth, int preYear, int currDay, int currMonth, int currYear)
{
    currDay--;
    if (currDay == 0)
    {
        currMonth--;
        if (currMonth == 0)
        {
            currMonth = 12;
            currYear--;
        }
        
        bool isLeap = (currYear % 4 == 0 && (currYear % 100 != 0 || currYear % 400 != 0));
        currDay = monthsDay[currMonth - 1];

        if (isLeap && currMonth == 2)
            currDay = 29;
    }

    return preDay == currDay && preMonth == currMonth && preYear == currYear;
}
int main()
{
    mino();
    int dates;
    while (cin >> dates, dates)
    {
        int day, month, year, consumption;
        int preDay = 0, preMonth = 0, preYear = 0, preConsumption = 0;
        int sumConsumption = 0, consecutiveDays = 0;
        while (dates--)
        {
            cin >> day >> month >> year >> consumption;

            if (isConsecutive(preDay, preMonth, preYear, day, month, year))
            {
                consecutiveDays++;
                sumConsumption += consumption - preConsumption;
            }

            preDay = day;
            preMonth = month;
            preYear = year;
            preConsumption = consumption;
        }
        cout << consecutiveDays << " " << sumConsumption << endl;
    }
}
