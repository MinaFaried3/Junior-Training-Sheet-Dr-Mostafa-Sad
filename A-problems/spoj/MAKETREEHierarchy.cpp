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

int Students, Successful_Students, Wishes, Position, a;
vector<vector<int>> Adj;
bool Visited[100074];
vector<int> Initial_Result;
int Parent[100074];

void Topological_Sort(int Student)
{
    Visited[Student] = true;
    for (int i = 0; i < (int)Adj[Student].size(); i++)
    {
        int child = Adj[Student][i];
        if (!Visited[child])
            Topological_Sort(child);
    }
    Initial_Result.push_back(Student);
}

int main()
{



    scanf("%d%d", &Students, &Successful_Students);

    Adj.resize(Students + 1);

    for (int i = 1; i <= Successful_Students; i++)
    {
        scanf("%d", &Wishes);
        for (int j = 0; j < Wishes; j++)
        {
            scanf("%d", &a);
            Adj[i].push_back(a);
        }
    }

    for (int i = 1; i <= Students; i++)
    {
        if (!Visited[i])
            Topological_Sort(i);
    }

    // cout << endl
    //      << endl;
    // for (int i = 0; i < Students; i++)
    // {
    //     cout << Initial_Result[i] << " ";
    // }
    // cout << endl
    //      << endl;

    Position = 0;
    for (int i = Students - 1; i >= 0; i--)
    {
        int Student = Initial_Result[i];
        Parent[Student] = Position;
        Position = Student;
    }

    for (int i = 1; i <= Students; i++)
    {
        printf("%d\n", Parent[i]);
    }

    return 0;
}