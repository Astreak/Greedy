#include<bits/stdc++.h>
using namespace std;
struct Job{
	char id;
	int dead;
	int profit;
	

};


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
vector<pair<int,int>> code(int *a,int *b,int n){
	vector<pair<int,int>> v;
	v.push_back(make_pair(a[0],b[0]));
	for(int i=1;i<n;i++){
		if(a[i]>=v[v.size()-1].second){
			v.push_back(make_pair(a[i],b[i]));
		}
	}
	return v;
}

//min-max product of subsets Comp..... O(N)

auto minProduct(int a[],int n){
	int prod=1;
	int min_reg=INT_MAX;
	int max_reg=INT_MIN;
	int Z=0;
	int N=0;
	int P=0; 
	if(n==1)
    	return a[0];
	for(int i=0;i<n;i++){
		if(a[i]==0){
			Z++;
			continue;
		}
		else if(a[i]<0){
			N++;
			max_reg=max(max_reg,a[i]);
		}
		else{
			P++;
			min_reg=min(min_reg,a[i]);
		}
		prod=prod*a[i];

	}
	if(N%2==0 && N!=0){
		prod=prod/max_reg;
	}
	else if(N==0 && !Z){
		return min_reg;
	}
	else if(Z!=0 && N==0)
		return 0;

	return prod;



}

auto maxProduct(int a[],int n){
	int prod=1;
	int Z=0;
	int N=0;
	int P=0;
	int min_n=INT_MAX;
	int max_n=INT_MIN;
	for(int i=0;i<n;i++){
		if(a[i]==0){
			Z++;
			continue;
		}
		else if(a[i]<0){
			N++;
			max_n=max(max_n,a[i]);

		}
		else{
			P++;
			min_n=min(min_n,a[i]);
		}
		prod=prod*a[i];

	}
	if(N%2!=0){
		prod=prod/max_n;
	}
	else if(P==0 && Z!=0){
		return 0;
	}
	return prod;



}

//max sum of subarray
auto maxSum(int a[],int n){
	int sum=0;
	int N=0;
	int P=0;
	int n_sum=0;
	int Z=0;
	int max_n=INT_MIN;
	for(int i=0;i<n;i++){
		if(a[i]<0){
			N++;
			n_sum+=a[i];
			max_n=max(max_n,a[i]);
		}
		else if(a[i]>0){
			P++;
			sum+=a[i];
		}
		else{
			Z++;

		}

	}
	if(N!=0 && P==0 && Z==0){
		return max_n;
	}
	else if(N!=0 && P==0 && Z!=0){
		return 0;
	}
	else if(N==0 && P==0 && Z!=0){
		return 0;
	}
	
	return sum;



}
//Job Sequence
bool condition(Job a,Job b){
	return (a.profit>b.profit);

}

auto jobSequence(auto a[],int n){
	sort(a,a+n,condition);
	
	vector<int>s;
	vector<Job>v;
	for(int i=0;i<n;i++){
		s.push_back(a[i].dead);
	}
	int slot[*max_element(s.begin(),s.end())];

	for(int i=0;i<=*max_element(s.begin(),s.end());i++){
		slot[i]=false;
	}
	v.push_back(a[0]);
	slot[0]=true;
	for(int i=1;i<=n;i++){
		for(int j=1;i<=*max_element(s.begin(),s.end());j++){
			if(slot[j]==false){
				if(a[i].dead>=j+1){
					slot[j]=true;
					v.push_back(a[i]);
					break;
				}
				else{
					break;
				}
			}
			

		}
	}

	
	return v;

}





auto code(int a[],int n,int k){
	sort(a,a+n);
	int sum=0;

	for(int i=0;i<k;i++){
		a[i]=-a[i];
	}
		

	auto u=maxSum(a,n);
	return u;

}







int main(){
	int A[]={-2, 0, 5, -1, 2} ; 
	Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 4, 27}, 
                   {'d', 1, 25}, {'e', 3, 15}}; ;
	auto y=code(A,5,4);
	cout<<y<<"\t"<<"\n";
	cout<<"____________________________________________"<<"\n";
	auto JS=jobSequence(arr,5);
	for(auto x: JS){
		cout<<x.id<<"\t";

	}
	cout<<"\n";


}