#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001];
stack<pair<int,int>> st;
int low[1001];
int disc[1001];
int parent[1001];
int countNo;
int even,odd;

void biConnected(int u){
	static int time=0;
	low[u]=disc[u]=++time;
	vis[u]=true;
	int subtree=0;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(vis[v]==false){
			subtree++;
			parent[v]=u;
			st.push(make_pair(u,v));
			biConnected(v);
			low[u]=min(low[u],low[v]);
			if((parent[u]!=-1 && low[v]>=disc[u]) || (parent[u]==-1 && subtree>1)){
				set<int> s;
				while(st.top().first != u || st.top().second != v){
					//cout<<st.top().first<<"--"<<st.top().second<<" ";
					s.insert(st.top().first);
					s.insert(st.top().second);
					st.pop();
					
				}
				//cout<<st.top().first<<"--"<<st.top().second<<endl;
				s.insert(st.top().first);
				s.insert(st.top().second);
				
				st.pop();
				int c=s.size();
				//cout<<"Set size "<<c<<endl;
				if(c%2==0){
					even++;
				}else{
					odd++;
				}
			}
		}
		else if(v!=parent[u]){
			low[u]=min(low[u],disc[v]);
			if(disc[v]<disc[u]){
				st.push(make_pair(u,v));
			}
		}
	}
}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(low,10001,sizeof(low));
	memset(disc,10001,sizeof(disc));
	memset(parent,-1,sizeof(parent));
	memset(vis,false,sizeof(vis));
	countNo=0;
	even=0;
	odd=0;
	for(int i=0;i<nodes;i++){
		if(vis[i]==false){
			biConnected(i);
			int j=0;
	set<int> s1;
	while(!st.empty()){
		j=1;
		//cout<<st.top().first<<"--"<<st.top().second<<",";
		s1.insert(st.top().first);
		s1.insert(st.top().second);
		st.pop();
	}
//	cout<<endl;
	int c1=s1.size();
	if(c1%2==0){
		even++;
	}
	else{
		odd++;
	}

		
		}
	}

	
	
	cout<<odd<<" "<<even<<endl;
	


}