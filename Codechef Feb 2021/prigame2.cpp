#include<bits/stdc++.h>
using namespace std;


bool isPrime(int n){
    if(n<=1)
        return false;
    
    if(n<=3)
        return true;
    
    if(n%2==0 || n%3==0)
        return false;

  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
    
    return true;
        
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int prime[1000001];
    int countTill[1000001];
    prime[0]=0;
    prime[1]=0;
    
    for(int i=2; i<1000001; i++){
        if(isPrime(i))
            prime[i]=1;
        else
            prime[i]=0;
        
        countTill[i] = countTill[i-1] + prime[i];
    }
    
	int t;
	cin>>t;
	
	while(t--){
	    
	    int x, y;
	    cin>>x>>y;
	    if(countTill[x]>y)
	        printf("Divyam\n");
	    else
	        printf("Chef\n");
	}
	return 0;
}
