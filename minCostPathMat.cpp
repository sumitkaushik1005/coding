#include<bits/stdc++.h>
using namespace std;
#define ROW 5 
#define COL 5 
int minPathDis(int grid[ROW][COL],int r,int c){
	int dis[r][c];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			dis[i][j]=INT_MAX;
		}
	}
	dis[0][0]=grid[0][0];
	set<pair<int,pair<int,int> > > st;
	set<pair<int,pair<int,int> > >::iterator it;
	st.insert(make_pair(0,make_pair(0,0)));
	int row[]={0,-1,0,1};
	int col[]={-1,0,1,0};
	while(!st.empty()){
		it=st.begin();
		int ui=(*it).second.first;
		int uj=(*it).second.second;
		st.erase(it);
		for(int k=0;k<4;k++){
			int vi=ui+row[k];
			int vj=uj+col[k];
			if(vi>=0 && vi<r && vj>=0 && vj<c && dis[vi][vj]>dis[ui][uj]+grid[vi][vj]){
				if(dis[vi][vj]!=INT_MAX){
					st.erase(st.find(make_pair(dis[vi][vj],make_pair(vi,vj))));
				}
				dis[vi][vj]=dis[ui][uj]+grid[vi][vj];
				st.insert(make_pair(dis[vi][vj],make_pair(vi,vj)));
			}
		}

	} 
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	 int grid[ROW][COL] = 
    { 
        31, 100, 65, 12, 18, 
        10, 13, 47, 157, 6, 
        100, 113, 174, 11, 33, 
        88, 124, 41, 20, 140, 
        99, 32, 111, 41, 20 
    };
    cout<<"hello"<<endl;
    minPathDis(grid,ROW,COL);
}