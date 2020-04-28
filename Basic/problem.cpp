#include<iostream>
using namespace std;
int fact(int x){
	if (x==1 || x==0)
		return 1;
	else
		return x*fact(x-1);
}
int code_of_colour(char t){
	switch(t){
		case 'B':
		return 0;
		case 'Y':return 1;
		case 'G':return 2;
		case 'R':return 3;
		default:return -1;
	}
}





void problem(char *a,char *b){
	int hit=0;
	int p=0;
	int FreqDist[4]={0};
	for(int i=0;i<4;i++){
		if (a[i]==b[i])
			hit++;
		else{
			int code=code_of_colour(a[i]);
			FreqDist[code]++;
		}
	}
	
	for (int i=0;i<4;i++){
		if (code_of_colour(b[i])>=0 && FreqDist[code_of_colour(b[i])]>0 && a[i]!=b[i])
			p++;
			//FreqDist[code_of_colour(b[i])]--;
		}
	
	cout<<"Pseudo-hits"<<p<<endl;
	cout<<"HIT"<<hit<<endl;
}





int main(){
	char C[5]="YYBB";
	char G[5]="YBBY";
	problem(C,G);
	
}
