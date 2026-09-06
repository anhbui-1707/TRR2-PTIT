#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w" , stdout);
	
	int t; cin >>t;
   int n; cin >>n;
   vector<int > p[101];
   int deg[101]={0};
   int b[n+1][n+1] = {0};
   for(int i = 1;i<=n;i++){
   	int x;
   	cin >>x;
   	deg[i] = x;
   	while(x--){
   		int y; cin >>y;
   		b[i][y] = 1;
	   }
   }
   if(t==1){
   	for(int i =1;i<=n;i++){
   		cout << deg[i]<< " ";
	   }
   }
   else{
   	cout << n << endl;
   	for(int i =1;i<=n;i++){
   		for(int j =1;j<=n;j++){
   			cout << b[i][j]<< " ";
		   }
		   cout << endl;
	   }
   }
	return 0;
}
