#include <iostream>
#include <map>
using namespace std;

map<string, string> parents;
map<string, int> ranks;

string find_set(string name)
{
    if (name == parents[name])
        return name;
    return parents[name] = find_set(parents[name]); // path compression
}

void link(string name1, string name2)
{
    if (ranks[name1] > ranks[name2])
        swap(name1, name2);
    parents[name1] = name2; // union by rank

    ranks[name2] += ranks[name1];
}

int union_sets(string name1, string name2)
{
    name1 = find_set(name1), name2 = find_set(name2);
    if (name1 != name2)
        link(name1, name2);
    return max(ranks[name1], ranks[name2]);
}

int main()
{
    int t, n;
    string name1, name2;
    cin >> t;
    while (t--)
    {
        cin >> n;
        parents.clear();
        ranks.clear();
        while (n--)
        {
            cin >> name1 >> name2;
            if (parents.count(name1) == 0)
            {
                parents[name1] = name1;
                ranks[name1] = 1;
            }
            if (parents.count(name2) == 0)
            {
                parents[name2] = name2;
                ranks[name2] = 1;
            }
            cout << union_sets(name1, name2) << endl;
        }
    }
    return 0;
}
