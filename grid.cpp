#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,q;
	cin>>n>>m>>q;
	char graph[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>graph[i][j];
		}
	}
	int ui,uj;
	cin>>ui>>uj;
	int dis[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dis[i][j]=INT_MAX;
		}
	}
	dis[ui-1][uj-1]=0;
	set< pair<int,pair<int,int> > >s;
	set< pair<int,pair<int,int> > >::iterator it;
	s.insert(make_pair(0,make_pair(ui-1,uj-1)));
	int r[]={0,0,-1,1};
	int c[]={-1,1,0,0};
	while(!s.empty()){
		it=s.begin();
		ui=(*it).second.first;
		uj=(*it).second.second;
		s.erase(it);
		for(int k=0;k<4;k++){
			int vi=ui+r[k];
			int vj=uj+c[k];
			if(vi>=0 && vi<n && vj>=0 && vj<m && graph[vi][vj]!='*' &&  (dis[vi][vj]>dis[ui][uj]+1)){
				if(dis[vi][vj]!=INT_MAX){
					s.erase(s.find(make_pair(dis[vi][vj],make_pair(vi,vj))));
				}
				dis[vi][vj]=dis[ui][uj]+1;
				s.insert(make_pair(dis[vi][vj],make_pair(vi,vj)));
			}
		}
	}
	while(q--){
	int di,dj;
	cin>>di>>dj;
	if(dis[di-1][dj-1]==INT_MAX){
		cout<<-1<<endl;
	}
	else{
		cout<<dis[di-1][dj-1]<<endl;
	}
	
	}
}