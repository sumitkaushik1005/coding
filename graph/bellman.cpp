#include<bits/stdc++.h>
using namespace std;
vector <int> v [2000 + 10];
int dis [1000 + 10];
int main(){
    int n;
    int m;
    cin>>n>>m;
    for(int i = 0; i < m + 2; i++){

        v[i].clear();
        dis[i] = 2e9;
    }

   for(int i = 0; i < m; i++){
        int from;
        int next;
        int weight;
        cin>>from>>next>>weight;
        v[i].push_back(from);
        v[i].push_back(next);
        v[i].push_back(weight);
   }

    dis[1] = 0;
    for(int i = 1; i < n ; i++){
        int j = 0;
        while(v[j].size() != 0){

            if(dis[ v[j][0]  ] + v[j][2] < dis[ v[j][1] ] ){
                dis[ v[j][1] ] = dis[ v[j][0]  ] + v[j][2];
            }
            j++;
        }
    }
    for(int i=0;i<m;i++){
        int x=v[i][0];
        int y=v[i][1];
        int wt=v[i][2];
        if(dis[x]+wt<dis[y]){
            cout<<"Negative cycle exist"<<endl;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
}
    