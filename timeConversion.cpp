#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
	int hour=(s[0]-'0')*10+(s[1]-'0');
	if(hour<12 && s[8]=='P')
		hour=hour+12;
	if(hour==12 && s[8]=='A')
		hour=0;
	printf("%02d",hour);
	string ans="";
	for(int i=2;i<=7;i++){
		ans+=s[i];
	}
	for(int i=0;i<=5;i++){
		printf("%c",ans[i]);
	}
	return "";
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}