#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.length();
        int open[n+1];
        int close[n+1];
        memset(open,0,sizeof(open));
        if(s[0]=='(')
            open[1]=1;
        for(int i=1;i<n;i++){
            if(s[i]=='('){
                open[i+1]=open[i]+1;
            }
            else
                open[i+1]=open[i];
        }
        if(s[n-1]==')')
            close[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(s[i]==')'){
                close[i]=close[i+1]+1;
            }
            else
                close[i]=close[i+1];
        }
        if(open[n]==0){
            cout<<n<<endl;
            return -1;
        }
        if(close[0]==0){
            cout<<0<<endl;
            return -1;
        }
        for(int i=0;i<=n;i++){
            if(open[i]==close[i]){
                cout<<i<<endl;
                return -1;
            }
        }
        
    }
	return 0;
}