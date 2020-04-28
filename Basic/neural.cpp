#include<bits/stdc++.h>
using namespace std;
void matmul(int inp[][3],int w[][1]){
	int res[][1];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			res[i][j]=0;
			for(int k=0;k<1;k++){
				res[i][j]+=inp[i][k]*w[k][j];
			}
		}
	}
	return res;
}

class Nn{
public:
	int weight[3][1];
	int b[1][1];
	Nn(int l){
		weight=		
		int learning_rate=l;

	}
	void train(int inp[3][3],int target[][1]){
		int output=matmul(inp,weight)+b;
		int error=output-target;
		weight-=learning_rate*




	}

}