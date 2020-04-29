#include<bits/stdc++.h>
using namespace std;
int minimumLenIndex(string arr[],int n){
	int len=INT_MAX;
	
	for(int i=0;i<n;i++){
		int l=arr[i].length();
		if(l<len){
			len=l;
			//index =i;
		}
	}
	return len;
}
bool anotherfn(string arr[],int n, string s,int start,int end){
	for(int i=0;i<n;i++){
		for(int j=start;j<=end;j++){
			if(arr[i][j] != s[j]){
				return false;
			}
		}
	}
	return true;
}
string fn(string arr[],int n){
	int k=minimumLenIndex(arr,n);
	string prefix="";
	int low=0;
	int high=k-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(anotherfn(arr,n,arr[0],low,mid)){
			prefix=prefix+arr[0].substr(low,mid-low+1);
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	return prefix;
}
int main(){
	string arr[] = {"geeksforgeeks", "geeks", 
                    "geek", "geezer"}; 
     int n=sizeof(arr)/sizeof(arr[0]);
     string ans=fn(arr,n);
     cout<<ans<<endl;
}