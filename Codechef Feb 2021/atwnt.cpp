// Shantanu Gupta
// PSIT, Kanpur
// Btech - CSE
// Shantanu_1118 <--> Codechef

// ------------------------------------------------------------

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod=1e5+5;
#define fo(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define v vector<int>


vector<int>adj[mod];
vector<int>total(mod,0);

void dfs(vector<int>graph[],vector<bool>&taken,int vert,int a,int &n_divisible){
   taken[vert]=true;
   int si=total[vert];
   if(si!=0&&a%si!=0){
       n_divisible+=a;
       return;
   }
   else { a=si==0?a:(a/si); }
   for(auto k:graph[vert]) {
       if(!taken[k]) {
          dfs(graph,taken,k,a,n_divisible);
       }
   }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;

    fo(i,1,n) {
        int elem;
        cin>>elem;
        adj[elem].pb(i+1);
        total[elem]++;
    }
    int query;
    cin>>query;
    while(query--) {
        vector<bool>taken(n+1,false);
        int n_divisible=0;
        int verte,w;
        cin>>verte>>w;
        dfs(adj,taken,verte,w,n_divisible);
        cout<<n_divisible<<"\n";
    }
    return 0;
}