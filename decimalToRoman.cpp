#include<bits/stdc++.h>
using namespace std;
int digit(char ch,int n,int i,char *c){
	for(int j=0;j<n;j++){
		c[i]=ch;
		i++;
	}
	return i;
}
int  sub_digit(char ch1,char ch2,int i,char *c){
	c[i]=ch1;
	i++;
	c[i]=ch2;
	i++;
	return i;
}
void fn(int n){
	char c[1001];
	int i=0;
	while(n!=0){
		if(n>=1000){
			i=digit('M',n/1000,i,c);
			n=n%1000;
	}
	else if(n>=500){
		if(n>=900){
			i=sub_digit('C','M',i,c);
			n=n%100;
		}
		else{
			i=digit('D',n/500,i,c);
			n=n%500;
		}
	}
	else if(n>=100){
		if(n>=400){
			i=sub_digit('C','D',i,c);
			n=n%100;
		}else{
			i=digit('C',n/100,i,c);
			n=n%100;
		}
	}
	else if(n>=50){
		if(n>=90){
			i=sub_digit('X','C',i,c);
			n=n%10;
		}else{
			i=digit('L',n/50,i,c);
			n=n%50;
		}
	}
	else if(n>=10){
		if(n>=40){
			i=sub_digit('X','L',i,c);
			n=n%10;
		}
		else{
			i=digit('X',n/10,i,c);
			n=n%10;
		}
	}
	else if(n>=5){
		if(n>=9){
			i=sub_digit('I','X',i,c);
			n=0;
		}else{
			i=digit('V',n/5,i,c);
			n=n%5;
		}
	}
	else if(n>=1){
		if(n>=4){
			i=sub_digit('I','V',i,c);
			n=0;
		}
		else{
			i=digit('I',n,i,c);
			n=0;
		}
	}
	}
	for(int j=0;j<i;j++){
		cout<<c[j];
	}
	
}
void fn2(int n){
	int num[] ={1,4,5,9,10,40,50,90,100,400,500,900,1000};
	string roman[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
	int i=12;
	while(n>0){
		int div=n/num[i];
		n=n%num[i];
		while(div--){
			cout<<roman[i];
		}
		i--;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
	cin>>n;
	//fn(n);
	fn2(n);
	cout<<endl;
	}
	
}