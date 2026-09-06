#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
	int t;cin>>t;
  int n; cin >>n;
   
   int deg_in[101]={0};
   int deg_out[101]={0};

   vector<pair<int,int>>p;
    for(int i = 1;i<=n;i++){
    	int x; cin >>x;
    	deg_out[i]= x;
    	while(x--){
    		int y;
    		cin >>y;
    		deg_in[y]++;
    	p.push_back({i,y});
		}
	}
   
   if(t==1){
     for(int i =1;i<=n;i++){
     	cout <<deg_in[i]<<" "<<deg_out[i]<<endl;
	 }
   }
   else{
  cout << n <<" "<<p.size()<<endl;
  for(auto it:p){
  	cout << it.first<<" "<<it.second<<endl;
  }
   
   }
}
