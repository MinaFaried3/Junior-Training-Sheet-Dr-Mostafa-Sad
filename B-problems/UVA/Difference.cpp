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

int jobNumbers, sumJobTimes;

int getMinJobTime(int queryJob, vector<int> jobTime, vector<vector<int>> beforeDependencies)
{
    int minJobTime = -jobTime[queryJob];
    queue<int> minJobTimes;
    vector<bool> visitedJobs(jobNumbers, false);

    minJobTimes.push(queryJob);
    visitedJobs[queryJob] = true;

    while (!minJobTimes.empty())
    {
        int currentJob = minJobTimes.front();
        minJobTimes.pop();
        minJobTime += jobTime[currentJob];

        for (int i = 0; i < beforeDependencies[currentJob].size(); i++)
        {
            int nextJob = beforeDependencies[currentJob][i];
            if (!visitedJobs[nextJob])
            {
                minJobTimes.push(nextJob);
                visitedJobs[nextJob] = true;
            }
        }
    }
    return minJobTime;
}

int getMaxJobTime(int queryJob, vector<int> jobTime,
                  vector<vector<int>> afterDependencies)
{
    int maxJobTime = sumJobTimes;
    queue<int> maxJobTimes;
    vector<bool> visitedJobs(jobNumbers, false);

    maxJobTimes.push(queryJob);
    visitedJobs[queryJob] = true;

    while (!maxJobTimes.empty())
    {
        int currentJob = maxJobTimes.front();
        maxJobTimes.pop();
        maxJobTime -= jobTime[currentJob];

        for (int i = 0; i < afterDependencies[currentJob].size(); i++)
        {
            int nextJob = afterDependencies[currentJob][i];
            if (!visitedJobs[nextJob])
            {
                maxJobTimes.push(nextJob);
                visitedJobs[nextJob] = true;
            }
        }
    }
    return maxJobTime;
}

int main()
{

    int caseNumber = 1, dependecyNumbers, jobX, jobY, queryNumbers, queryJob;

    cin >> jobNumbers >> dependecyNumbers;

    while (jobNumbers != 0 || dependecyNumbers != 0)
    {

        sumJobTimes = 0;
        vector<int> jobTime(jobNumbers);
        vector<vector<int>> beforeDependencies(jobNumbers);
        vector<vector<int>> AfterDependencies(jobNumbers);

        for (int i = 0; i < jobNumbers; i++)
        {
            cin >> jobTime[i];
            sumJobTimes += jobTime[i];
        }

        while (dependecyNumbers--)
        {
            cin >> jobX >> jobY;
            jobX--, jobY--;

            beforeDependencies[jobX].push_back(jobY);
            AfterDependencies[jobY].push_back(jobX);
        }
        cin >> queryNumbers;

        cout << "Case #" << caseNumber++ << ":" << endl;
        while (queryNumbers--)
        {
            cin >> queryJob;
            queryJob--;

            cout << getMaxJobTime(queryJob, jobTime, AfterDependencies) - getMinJobTime(queryJob, jobTime,
                                                                                        beforeDependencies)
                 << endl;
        }

        cout << endl;
        cin >> jobNumbers >> dependecyNumbers;
    }
    return 0;
}