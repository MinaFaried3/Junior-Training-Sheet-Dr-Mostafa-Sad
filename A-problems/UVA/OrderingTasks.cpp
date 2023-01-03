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

vector<vector<int>> adj;
vector<bool> visited;
vector<int> result;

void topologicalSort(int task)
{
    visited[task] = true;

    for (int &child : adj[task])
    {
        if (!visited[child])
            topologicalSort(child);
    }

    result.push_back(task);
}

int main()
{
    mino();

    int tasks, relations;
    while (cin >> tasks >> relations && tasks)
    {
        result.clear();
        adj.clear();
        visited.clear();
        adj = vector<vector<int>>(tasks + 1);
        visited = vector<bool>(tasks + 1, false);

        loop0(relations)
        {
            int before, after;
            cin >> after >> before;

            adj[after].push_back(before);
        }

        loop1(tasks)
        {
            if (!visited[i])
                topologicalSort(i);
        }

        for (int i = result.size() - 1; i >= 0; i--)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
}