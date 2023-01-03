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
#define loop0(n) for (size_t i = 0; i < n; i++)
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

vector<vector<int>> graph;
vector<bool> visited;

enum GraphStatus
{
    PATH = 0,
    CYCLE = 1
};

GraphStatus dfs(int currStudent, int parentStudent, int &count)
{
    if (visited[currStudent])
        return CYCLE;

    visited[currStudent] = true;

    for (int childStudent : graph[currStudent])
        if (childStudent != parentStudent)
        {

            count++;

            if (dfs(childStudent, currStudent, count) == CYCLE)
                return CYCLE;
        }

    return PATH;
}

int main()
{
    int studentsNum, enemies;
    cin >> studentsNum >> enemies;
    graph = vector<vector<int>>(studentsNum);
    visited = vector<bool>(studentsNum, false);

    while (enemies--)
    {
        int enmityFromStudent, enmityToStudent;
        cin >> enmityFromStudent >> enmityToStudent;

        enmityFromStudent--, enmityToStudent--;
        graph[enmityFromStudent].push_back(enmityToStudent);
        graph[enmityToStudent].push_back(enmityFromStudent);
    }

    int benchStudents = 0;

    loop0(studentsNum) if (!visited[i])
    {
        int count = 0;

        GraphStatus currGraph = dfs(i, -1, count);

        if (currGraph == CYCLE)
            benchStudents += (count % 2 != 0);
    }

    if ((studentsNum - benchStudents) % 2 != 0)
        benchStudents++;

    cout << benchStudents;
}