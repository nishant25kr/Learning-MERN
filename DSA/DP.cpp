#include <iostream>
#include <vector>
using namespace std;

int f(int n, vector<int> &dp){
    if(n<=1){
        return n;
    }

    if( dp[n] != -1 ) return dp[n];

    return dp[n] = f(n-1, dp) + f(n-2, dp);
}


int fn(int n){
    if(n<=1){
        return n;
    }
    return fn(n-1)+fn(n-2);
}

int main(){
    int n=5;
    // cin >> n;
    vector<int> dp(n+1 ,-1);
    // cout<<f(n, dp);
    cout<<fn(n);
    return 0;
}