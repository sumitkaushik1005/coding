#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            dict.push_back(s);
        }
        if(find(dict.begin(),dict.end(),"sumit")!=dict.end()){
            cout<<"Yest"<<endl;
        }
    }
	return 0;
}