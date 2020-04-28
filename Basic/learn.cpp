#include<bits/stdc++.h>
using namespace std;

string Foating_part(string s){

	int y=s.find(".");
	string h=s.substr(y+1,s.length()-y+1);
	return h;
}





int main(){
	string A ="Hey Do you wanna.. Get ...into the party";
	string b(" OK No problem");
	 A.replace(A.length()-1,1,b);
	int  p=A.find("..");//returns index
	int  n=A.find("...");//returns index
	A.replace(p,1," ");
	A.replace(n,1," ");
	cout<<A<<endl;
	string r=Foating_part("12.345");
	cout<<r<<endl;
	r.clear();
	if (r.empty()){
		cout<<"FUCK OFF"<<endl;
	}



}

