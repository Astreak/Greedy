#include<bits/stdc++.h>
using namespace std;
void pairSort(int a[],int b[],int n){ //a is finish
	pair<int,int> *p;
	p=new pair<int,int>[n];
	
	for(int i=0;i<n;i++){
		p[i].first=a[i];
		p[i].second=b[i];

	}
	sort(p,p+n);
	for(int i=0;i<n;i++){
		a[i]=p[i].first;
		b[i]=p[i].second;
	}


}
int code(int *a,int *b,int n){
	vector<pair<int,int>> v;
	v.push_back(make_pair(a[0],b[0]));
	for(int i=1;i<n;i++){
		if(a[i]>=v[v.size()-1].second){
			v.push_back(make_pair(a[i],b[i]));
		}
	}
	return v.size();



 }




int main(){
	int s[] ={1, 3, 0, 5, 8, 5};
	int f[] ={2, 4, 6, 7, 9, 9}; 
	pairSort(f,s,6);
	int k=code(s,f,6);
	cout<<k<<"\t";

}