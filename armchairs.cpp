#include <bits/stdc++.h>

using namespace std;

int memo[10000][10000];
int n,p[10000],br;
vector <int> v;

int dynamic (int x,int y){
	if (y==0){
		return 0;
	}
	if (x==n){
		return 0x3f3f3f3f;
	}
	if (memo[x][y]!=0){
		return memo[x][y];
	}
	if (p[x]==1){
		memo[x][y]=dynamic(x+1,y);
		return memo[x][y];
	}
	memo[x][y]=dynamic(x+1,y);
	memo[x][y]=min(memo[x][y],dynamic(x+1,y-1)+abs(x-v[br-y]));
	return memo[x][y];
} 

int main (){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>p[i];
		if (p[i]==1){
			br++;
			v.push_back(i);
		}
	}
	cout<<dynamic(0,br);
	return 0;
}
