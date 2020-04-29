#include<bits/stdc++.h>
using namespace std;
int first(int a[],int l,int h,int x){
    if(h>=l){
        int mid=(l+h)/2;
        if(mid==0 || a[mid]==x && a[mid-1]<x){
            return mid;
        }
        else if(a[mid]<x){
            return first(a,mid+1,h,x);
        }
        else
        return first(a,l,mid-1,x);
    }
    return -1;
}
int last(int a[],int l,int h,int x){
    if(h>=l){
        int mid=(l+h)/2;
        if(mid==h || a[mid]==x && a[mid+1]>x){
            return mid;
        }
        else if(a[mid] > x){
            return last(a,l,mid-1,x);
        }
        else 
            return last(a,mid+1,h,x);
    }
    return -1;
}
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<first(a,0,n-1,x)<<" "<<last(a,0,n-1,x)<<endl;
    }
	return 0;
}