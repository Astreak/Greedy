#include<iostream>
#include<cmath>
using namespace std;

void InsertionSort(int a[],int n){
	int i,j;
	for(i=1;i<n;i++){
		int key=i;
		j=i-1;
		while(j>=0 && a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
int Recursion(int a,int b){
	if(b==1)
		return a;
	else
		return a+Recursion(a,b-1);
}


int factorial(int n){
	if (n==1)
		return 1;
	else
		return n*factorial(n-1);
}

int exponential(int v,int n){
	if(n==1)
		return (pow(v,0)/(factorial(0)));
	else
		return (pow(v,n-1)/(factorial(n-1))+exponential(v,n-1));
}
	


int  BinarySearch1(int a[],int low,int high,int value){
	int flag=0;
	int mid=(low+high)/2;
	if(low<=high){
		
		if(a[mid]==value){
			flag =1;
			return mid+1;
		}
		else if(a[mid]>value)
			return BinarySearch1(a,low,mid-1,value);
		else
			return BinarySearch1(a,mid+1,high,value);
	}
	return -1;

	
	
}

		
	
		
	


void print(int a[],int n){
	for (int i=0;i<n;i++){
		cout<<a[i]<<endl;
	}
}

int main(){
	int A=Recursion(3,10);
	cout<<A<<endl;
	cout<<exponential(2,3);
	
	
}
	

			

