#include<bits/stdc++.h>
using namespace std;
vector<int> adj[50000];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int population[n];
		set<int> st;
		for(int i=0;i<n;i++){
			int p;
			cin>>p;
			st.insert(p);
			population[i]=p;
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<int> ans;
		for(int i=4;i<=n;i++){
			int u=i;
			int p_u=population[i-1];		
			st.erase(p_u);
			for(int j=0;i<adj[u].size();j++){
				int v=adj[u][j];
				cout<<v<<endl;
				int p_v=population[v-1];
				st.erase(p_v);
			}
			auto it=st.rbegin();
			
			int capital;
			for(int i=0;i<n;i++){
				if(population[i]==*it){
					capital=i+1;
					break;
				}
			}
			ans.push_back(capital);
			st.insert(p_u);
			for(int j=0;j<adj[u].size();j++){
				int v=adj[u][j];
				int p_v=population[v-1];
				st.insert(p_v);
			}
			break;
		}
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
	}
}