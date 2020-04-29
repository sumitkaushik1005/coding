	#include<bits/stdc++.h>
	using namespace std;
	const int ll =	1e6;
	const long mod=1e9+7;
	vector<int> adj[ll];
	stack<int> st;
	queue<int> q;
	int in_deg[ll];
	int dp[ll];
	void topSort(){
		while(!q.empty()){
			int u=q.front();
			st.push(u);
			q.pop();
			vector<int>::iterator it;
			for(it=adj[u].begin();it!=adj[u].end();it++){
				in_deg[*it]--;
				if(in_deg[*it]==0){
					q.push(*it);
				}
			}
		}
	}
	int main(){
		int nodes,edges;
		cin>>nodes>>edges;
		int a,b;
		cin>>a>>b;
		for(int i=0;i<edges;i++){
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
		}
		memset(in_deg,0,sizeof(in_deg));
		memset(dp,0,sizeof(dp));
		dp[b]=1;
		for(int i=1;i<=nodes;i++){
			vector<int>::iterator it;
			for(it=adj[i].begin();it!=adj[i].end();it++){
				in_deg[*it]++;
			}
		}
		for(int i=1;i<=nodes;i++){
			if(in_deg[i]==0){
				q.push(i);
			}
		}
		topSort();
		while(!st.empty()){
			int u=st.top();
			st.pop();
			vector<int>::iterator it;
			for(it=adj[u].begin();it!=adj[u].end();it++){
				int v=*it;
				//cout<<u<<" "<<v<<endl;
				dp[u]+=dp[v];
				dp[u]=dp[u]%mod;
			}
			
		}
		
		cout<<dp[a]<<endl;
	}