#include<bits/stdc++.h>
using namespace std;
#define INT_BITS 32
int leftRotate(int n, unsigned int d) 
{ 
      
    /* In n<<d, last d bits are 0. To 
     put first 3 bits of n at  
    last, do bitwise or of n<<d  
    with n >>(INT_BITS - d) */
    return (n << d)|(n >> (INT_BITS - d)); 
} 
int main(){
	int n=1;
	for(int i=1;i<=32;i++){
	long long n=leftRotate(n,1);
	cout<<n<<endl;
	
	}
	
}