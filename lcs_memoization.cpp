#include<bits/stdc++.h>
using namespace std;

int dp[101][101];

int lcs_memo(string x, string y, int n, int m){
    //initialize all the blocks with -1
    memset(dp, -1, sizeof(dp));

    //base condition
    if(n==0 || m==0)
        return dp[n][m] = 0;
    
    if(dp[n][m] != -1)
        return dp[n][m];
    
    if(x[n-1] == y[m-1])
        return dp[n][m] = 1 + lcs_memo(x, y, n-1, m-1);
    else
        return dp[n][m] = max(lcs_memo(x, y, n-1, m), lcs_memo(x, y, n, m-1));   
}

int main(){
    string x,y;
    cin>>x;
    cin>>y;
    int n = x.length();
    int m = y.length();

    cout<<"LONGEST COMMON SUBSEQUENCE IS : "<<lcs_memo(x, y, n, m);
    return 0;
}