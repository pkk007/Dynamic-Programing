#include<bits/stdc++.h>
using namespace std;

int lcs(string x, string y, int n, int m){
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

int min_insertion_to_make_palindrome(string x, int n){
    string y = x;
    reverse(y.begin(), y.end());
    int m = n;
    //no of deletion = no. of insertion
    int noOf_del = n - lcs(x,y,n,m);
    int noOf_ins = noOf_del;
    return noOf_ins;
}

int main(){
    string x;
    cin>>x;
    int n = x.length();

    cout<<"NO. OF INSERTION IS : "<<min_insertion_to_make_palindrome(x,n);
    return 0;
}