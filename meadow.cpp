#include <bits/stdc++.h>

using namespace std;

int n,k,w,p[500];
int memo[500][500];

int dynamic (int a,int b){
	if (b==k){
		return 0;
	}
	if (memo[a][b]!=0){
		return memo[a][b];
	}
	if (a+1<=n){
		memo[a][b]=dynamic(a+1,b);
	}
	int mini=0x3f3f3f3f;
	for (int i=a;i<min(a+w,n);i++){
		mini=min(mini,p[i]);
		memo[a][b]=max(memo[a][b],dynamic(i+1,b+1)+(i-a+1)*mini);
	}
	return memo[a][b];
}

int main (){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	cin>>k;
	cin>>w;
	vector <int> v;
	for (int i=0;i<n;i++){
		cin>>p[i];
		v.push_back(p[i]);
	}
	if (w==1){
		int rj=0;
		sort(v.begin(),v.end());
		for (int i=n-1;i>=n-k;i--){
			rj=rj+v[i];
		}
		cout<<rj;
	}
	else {
		cout<<dynamic(0,0);
	}
	return 0;
}
