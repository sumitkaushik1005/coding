#include<bits/stdc++.h>
using namespace std;
bool comparator(int a,int b){
    int n1=a*10+b;
    int n2=b*10+a;
    return ((n1>n2)?1:0);
    
}
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end(),comparator);
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
	return 0;
}