#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define endl '\n'
#define y1 holyshit
#define all(x) x.begin(),x.end()
const int inf=0x3f3f3f3f;

int N;
ll d[1000010],s[1000010],e[1000010];
ll ans;
stack<int> st;

void work(){
    for(int i=0;i<N;i++) s[i]=0,e[i]=N-1;
	for(int i=0;i<N;i++){
        	while(!st.empty()&&d[st.top()]<=d[i]){
            		e[st.top()]=i-1;
            		st.pop();
        	}
        	st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i=N-1;i>=0;i--){
		while(!st.empty()&&d[st.top()]<d[i]){
		    s[st.top()]=i+1;
		    st.pop();
		}
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i=0;i<N;i++) ans+=d[i]*((e[i]-i)*(i-s[i])+e[i]-s[i]+1);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) cin>>d[i];
	work();
	for(int i=0;i<N;i++) d[i]*=-1;
	work();
	cout<<ans;
	return 0;
}