#include<bits/stdc++.h>
using namespace std;

void cll(vector<int>adj[],int v,int u){
     adj[v].push_back(u);
     adj[u].push_back(v);

}
void print(vector<int>V[],int v){
     for(int i=0;i<v;i++){
          cout<<"Adjacency list of vertex"<<i;
          for(auto x:V[i]){
               cout<<"-->"<<x<<endl;

          }
     }

}


int main(){
     vector<int>V[5];
     cll(V,0,1);
     cll(V,1,2);
     print(V,5);

      
}