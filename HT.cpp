#include <bits/stdc++.h>

using namespace std;

long long n,d;
long long a[1000000];
vector <long long> v,k;
int memo[1000000];

int dynamic (int p){
	if (p==n){
		return 1;
	}
	int maxi=n,mini=n-p,mid,pr=0;
	while (maxi>mini){
		mid=(mini+maxi)/2;
		if (k[mid]<=v[p]+d){
			mini=mid+1;
			pr=1;
		}
		else {
			maxi=mid;
		}
	}
	mini=mini-n+p+1;
	if (pr==0){
		mini=1;
	}
	memo[p]=dynamic(p+1)*mini;
	return memo[p];
}

int main (){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	cin>>d;
	for (int i=0;i<n;i++){
		cin>>a[i];
		v.push_back(a[i]);
		k.push_back(a[i]);
	}
	sort(k.begin(),k.end());
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	cout<<dynamic(0);
	return 0;
}
