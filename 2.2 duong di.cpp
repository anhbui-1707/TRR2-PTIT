#include<bits/stdc++.h>
using namespace std;

int n,u,v;
int a[101][101];
int used[101] = {0};
int truoc[101]={0};
void nhap(){
	cin >>n>>u>>v;
	for(int i =1;i<=n;i++){
		for(int j =1;j<=n;j++){
			cin >>a[i][j];
		}
	}
}
void bfs(int u){
  queue<int> q;
  q.push(u);
  used[u] = 1;
   while(!q.empty()){
   	  int s = q.front();
   	  q.pop();
   	  for(int i =1;i<=n;i++){
   	  	if(used[i] == 0 && a[s][i] == 1){
   	  		used[i] =1;
   	  		q.push(i);
   	  		truoc[i] = s;
			 }
		 }
   }
}
void in(){
	if(used[v] == 0){
		cout << 0 <<endl;
		return;
	}
	else{
		vector<int> p;
		while(v!= u){
			p.push_back(v);
			v = truoc[v];
		}
		p.push_back(u);
		reverse(p.begin(),p.end());
		for(int x : p){
			cout << x <<" ";
		}
	}
}
int main(){
	freopen("TK.INP","r",stdin);
	freopen("TK.OUT","w",stdout);
	
	int t;cin>>t;
    if(t==1){
     nhap();
     int cnt = 0;
     for(int k = 1;k<=n;k++){
     	if(a[u][k] == 1 && a[k][v]==1){
     		cnt++;
		 }
	 }
	 cout <<  cnt << endl;
	}
	else{
		nhap();
		bfs(u);
		in();
	}
}
