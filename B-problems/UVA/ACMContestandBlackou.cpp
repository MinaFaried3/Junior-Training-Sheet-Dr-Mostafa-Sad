
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

struct Edge {
	int from, to, weight,index;
	bool del;
	Edge(int f, int t, int w,int idx) {
		from = f;
		to = t;
		weight = w;
		index = idx;
		del = false;
	}
	bool operator < (const Edge & e) const {
		return weight > e.weight;
	}
	bool operator == (const Edge & e) const {
		return ( from == e.from && to == e.to && weight == e.weight);
	}
};

struct DisJointSet{
	vector <int> ranks;
	vector <int> parent;

	DisJointSet(int n){
		ranks.resize(n,0);
		parent.resize(n);

		for(int i = 0;i < n;i++)
			parent[i] = i;
	}
	int findSet(int x){
		if(parent[x] == x) return x;
		return parent[x] = findSet(parent[x]);
	}

	void link(int x, int y){
		if(ranks[x] > ranks[y])
			swap(x,y);
		parent[x] = y;
		if(ranks[x] == ranks[y])
			ranks[y]++;
	}
	bool unionSet(int x, int y){
		int parentX = findSet(x), parentY = findSet(y);
		if(parentX != parentY){
			link(parentX,parentY);
			return true;
		}
		return false;
	}

};


pair< int , vector < Edge > >  getMST(int n,vector< Edge > edges) {
	int cost = 0;
	priority_queue <Edge> q;
	vector <Edge> res;

	DisJointSet djSet(n);

	for(int i = 0;i < edges.size();i++){
		if(!edges[i].del)
			q.push(edges[i]);
	}

	while(!q.empty()){
		Edge curE = q.top();
		q.pop();
		if(djSet.unionSet(curE.from,curE.to)){
			cost +=curE.weight;
			res.push_back(curE);
		}
	}
	if(res.size()!= n-1)
		return make_pair(INT_MAX,vector <Edge>());
	return make_pair(cost,res);
}

void PrepareMSTList(int n, int e){
	int a, b, w;
	vector < Edge > edges;
	for(int i = 0;i < e;i++){
		cin >> a >> b >> w;
		a--,b--;
		edges.push_back(Edge(a,b,w,i));
	}
	pair< int , vector < Edge > > res =  getMST(n,edges);
	int secondMinCost = INT_MAX;
	for(int i = 0 ;i < res.second.size();i++){
		edges[res.second[i].index].del = true;

		pair< int , vector < Edge > > res2 = getMST(n,edges);
		secondMinCost = (res2.first < secondMinCost)?res2.first:secondMinCost;

		edges[res.second[i].index].del = false;
	}
	cout << res.first <<" "<<secondMinCost << endl;
}

int main() {
	int t, n, e;
	cin >> t;
	while (t--) {
		cin >> n >> e;
		PrepareMSTList(n,e);
	}

	return 0;
}
