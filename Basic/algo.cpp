#include<bits/stdc++.h>
using namespace std;
void p(string s){
	map< pair<char,char>, int> D;
	for(int i=0;i<s.size()-1;i++){
		D[make_pair(s[i],s[i+1])]++;
	}
	cout<<"there you go"<<endl;

	for(auto i=D.begin();i!=D.end();i++){
		cout<<i->first.first<<i->first.second<<"-"<<i->second<<endl;
	}

}

auto PAIR(){
	pair<int,pair<int ,string>> P;
	P.first=100;
	P.second.first=56;
	P.second.second="A";
	pair<string,int> S;
	S=make_pair("ok mate",123);
	cout<<S.first<<" ";
	cout<<S.second<<"\n";

}

auto frequency(auto a){
	map<int ,int> OK;
	int count=0;
	for(int i=0;i<a.size();i++){
		OK[a[i]]++;
	}
	
	return OK;
}

auto check(){
	char a[5]="oklo";
	string s="pop";
	const char* b="geeks";
	a[0]='p';
	s[0]='o';
	cout<<a<<endl;
	cout<<b<<endl;



}







int main(){
	string h="aabsaahjkl";
	p(h);
	PAIR();
	vector<int> v={12,3,12,-1,-1,90};
	set<int> s;
	auto OK=frequency(v);
	for(auto i=OK.begin();i!=OK.end();i++){
		cout<<i->first<<"--->"<<i->second<<endl;
	}
	check();

}