#include<bits/stdc++.h>
using namespace std;

int longest_rep_subseq(string x, string y, int n, int m){
    int dp[n+1][m+1]; 

    //initialization
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
    for(int j=0; j<=m; j++)
        dp[0][j] = 0;

    //choice diagram
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if((x[i-1] == y[j-1]) && i!=j)
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }

    return dp[n][m];
}


int main(){
    string x;
    cin>>x;
    string y = x;
    int n = x.length();
    int m = n;

    cout<<"LONGEST REPEATING SUBSEQUENCE IS : "<<longest_rep_subseq(x, y, n, m);
    return 0;
}