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
#define sz(v) ((lol)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define loop(n) for (int i = 0; i < n; i++)
#define loopx(n) for (int x = 0; x < n; x++)
#define loopR(x, n) for (int i = x; i <= (int)(n); ++i)
#define loopSz(v) for (int i = 0; i < sz(v); ++i)
#define loopItr(structure) for (auto itr = structure.begin(); itr != structure.end(); itr++)
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
vector<vector<lol>> graph;
vector<bool> visited;
set<pair<lol, lol>> connectedGraphEdges;
lol countVertex = 0;

void dfs(lol node)
{
    visited[node] = true;
    countVertex++;

    loopSz(graph[node])
    {
        if (graph[node][i] > node)
            connectedGraphEdges.insert({node, graph[node][i]});
        else if (graph[node][i] < node)
            connectedGraphEdges.insert({graph[node][i], node});

        if (!visited[graph[node][i]])
            dfs(graph[node][i]);
    }
}

int main()
{
    mino;
    lol node_count, edges;
    cin >> node_count >> edges;
    graph = vector<vector<lol>>(node_count + 1);
    visited = vector<bool>(node_count + 1, false);

    loop(edges)
    {
        lol to, from;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for (lol i = 1; i <= node_count; i++)
    {

        if (!visited[i])
        {
            connectedGraphEdges.clear();
            countVertex = 0;
            dfs(i);

            lol equ = (countVertex * (countVertex - 1)) / 2;
            if (equ != sz(connectedGraphEdges))
            {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";
}

/*
4 6
3 1
2 3
3 4
1 2
4 1
4 2

4 5
3 1
2 3
3 4
1 2
4 2
*/