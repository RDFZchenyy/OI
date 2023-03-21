#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
#define MAXN 1000005

struct P{
	LL val;
	int num;
}ps[2*MAXN]; 

bool cmp(P a,P b){
	return a.val>=b.val;
}

int n;
LL p,q; 
LL a[MAXN],cnt[MAXN],ans;
stack<int> s[3];
int main(){
	scanf("%d",&n);
	scanf("%lld %lld",&p,&q);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		ps[2*i].num=i;
		ps[2*i].val=p*a[i];
		ps[2*i+1].num=i;
		ps[2*i+1].val=q*a[i];
	}
	sort(ps,ps+2*n,cmp);
	for(int i=0;i<n;i++){
		ans+=ps[i].val-ps[n+i].val;
		cnt[ps[i].num]++;
	}
	printf("%lld\n",ans);
	for(int i=0;i<n;i++){
		s[cnt[i]].push(i);
	}
	if(p>q){
		for(int i=1;i<=n;){
			if(!s[0].empty()){
				printf("%lld %lld ",a[s[0].top()],a[s[2].top()]);
				s[0].pop();
				s[2].pop();
				i+=2;
			}else{
				printf("%lld ",a[s[1].top()]);
				s[1].pop();
				i++;
			}
		}
	}else{
		for(int i=1;i<=n;){
			if(!s[0].empty()){
				printf("%lld %lld ",a[s[2].top()],a[s[0].top()]);
				s[0].pop();
				s[2].pop();
				i+=2;
			}else{
				printf("%lld ",a[s[1].top()]);
				s[1].pop();
				i++;
			}
		}		
	}
	
	return 0;
}
