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

int LPS(string a, int n){
    string b = a;
    int m = n;
    reverse(a.begin(), a.end());
    return lcs(a,b,n,m);
}

int min_deletion_to_make_a_palindrome(string a, int n){
    return (n - LPS(a,n));
}

int main(){
    string a;
    cin>>a;
    int n = a.length();

    cout<<"NO. OF DELITION IN A STRING TO MAKE IT A PALINDROME IS : "<<min_deletion_to_make_a_palindrome(a, n);
    return 0;
}