#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > adj[1001];
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		adj[u].push_back(make_pair(v,wt));
		adj[v].push_back(make_pair(u,wt));
	}
	int src=1;
	vector<int> dis(nodes+1,2000);
	dis[src]=0;
	set<pair<int,int> > st;
	set<pair<int,int> >:: iterator it;
	st.insert(make_pair(0,src));
	while(!st.empty()){
		it=st.begin();
		st.erase(it);
		int u=it->second;
		for(auto i=adj[u].begin();i!=adj[u].end();i++){
			int v=i->first;
			int wt=i->second;
			if(dis[v]>dis[u]+wt){
				if(dis[v]!=2000){
					st.erase(st.find(make_pair(dis[v],v)));
				}
				dis[v]=dis[u]+wt;
				st.insert(make_pair(dis[v],v));
			}
		}

	}
	for(int i=1;i<=nodes;i++){
		cout<<dis[i]<<" ";
	}
}