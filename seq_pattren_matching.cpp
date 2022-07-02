#include<bits/stdc++.h>
using namespace std;

int lcs_table_fill(string x, string y, int n, int m){
    //create a dp matrix
    int dp[n+1][m+1];
    //insiatilization
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
    for(int j=0; j<=m; j++)
        dp[0][j] = 0;
    
    //choice diagram
    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

bool seq_patt_match(string x, string y, int n, int m){
    if(lcs_table_fill(x,y,n,m) == n)
        return true;
    else
        return false;
}

int main(){
    string x,y;
    cin>>x;
    cin>>y;
    int n = x.length();
    int m = y.length();

    if(seq_patt_match(x,y,n,m))
        cout<<"STRING X IS SUBSEQUENCE OF STRING Y";
    else
        cout<<"STRING X IS NOT A SUBSEQENCE OF STRING Y";
    return 0;
}