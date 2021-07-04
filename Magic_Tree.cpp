#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int u[100005],d[100005],w[100005];
vector <int> bv[1000005],v[1000005];
pair <int,int> niz[100005];
int memo[1005][10005],p[1000005 ];

int dynamic (int cv,int vr){
	if (memo[cv][vr]!=0){
		return memo[cv][vr];
	}
	memo[cv][vr]=0;
	int op1=0,op2=0;
	for (int i=0;i<v[cv].size();i++){
		if (niz[v[cv][i]].first<vr and niz[v[cv][i]].first>0){
			op1=dynamic(v[cv][i],niz[v[cv][i]].first)+niz[v[cv][i]].second;
		}
		op2=dynamic(v[cv][i],vr);
		memo[cv][vr]=memo[cv][vr]+max(op1,op2);
	}
	return memo[cv][vr];
}

void dfs (int x,int y){
	for (int i=0;i<bv[x].size();i++){
		if (niz[bv[x][i]].first!=0){
			v[y].push_back(bv[x][i]);
			dfs(bv[x][i],bv[x][i]);
		}
		else {
			dfs(bv[x][i],y);
		}
	}
}

int main (){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	cin>>m;
	cin>>k;
	int bez;
	for (int i=0;i<n-1;i++){
		cin>>bez;
		bv[bez-1].push_back(i+1);
	}
	memset(niz,0,sizeof niz);
	for (int i=0;i<m;i++){
		cin>>u[i];
		cin>>d[i];
		cin>>w[i];
		niz[u[i]-1]=make_pair(d[i],w[i]);
	}
	dfs(0,0);
	/*for (int i=0;i<n;i++){
		for (int j=0;j<v[i].size();j++){
			cout<<v[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	cout<<dynamic(0,99);
	return 0;
}
