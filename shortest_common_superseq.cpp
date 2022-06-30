#include<bits/stdc++.h>
using namespace std;

int lcs(string x, string y, int n, int m){
    //create a dp matrix
    int dp[n+1][m+1];

    //iniatlization
    for(int j=0; j<=m; j++)
        dp[0][j] = 0;
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
    
    //choice diagram
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int shortest_common_supersequence(string x, string y, int n, int m){
    return (n+m - lcs(x,y,n,m));
}

int main(){
    string x,y;
    cin>>x;
    cin>>y;
    int n = x.length();
    int m = y.length();

    cout<<"LENGTH OF SHORTEST COMMON SUPER SEQUENCE IS : "<<shortest_common_supersequence(x, y, n, m);
    return 0;
}