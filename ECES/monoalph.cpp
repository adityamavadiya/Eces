#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	string s;
	cout<<"Enter plain text :";
	getline(cin,s);
	cout<<"Enter key :";
	string key;
	getline(cin,key);
	vector<int> pt(26,-1);
	vector<int> ky(26,-1);
	cout<<"Encrypted message is : ";
	int j=0;
	for(int i=0;i<s.length();i++){
		if(s[i]==' '){
			cout<<s[i];
			continue;		
		}
		if(s[i]>='a' && s[i]<='z'){
			if(pt[s[i]-'a']!=-1){
				cout<<(char)(pt[s[i]-'a']);
				continue;
			}
			while(key[j]==' '){
				j++;
				if(j==key.length()){
					j=0;
					for(int l=0;l<26;l++) ky[l]=-1;
				}
			}
			while(j<key.length() && ky[key[j]-'a']!=-1){
				j++;
				if(j==key.length()){
					j=0;
					for(int l=0;l<26;l++) ky[l]=-1;
				}
			}
			ky[key[j]-'a']=1;
			pt[s[i]-'a']=key[j];
			cout<<key[j];
			j++;
		}
	}
	cout<<endl;
	return 0;
}
