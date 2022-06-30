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

void min_NoOf_del_insert_toCoonvert_string_aTob(string a, string b, int n, int m){
    cout<<"NO. OF DELETION : "<<(n - lcs(a,b,n,m))<<"\n";
    cout<<"NO, OF INSERTION : "<<(m - lcs(a,b,n,m));
}

int main(){
    string a,b;
    cin>>a;
    cin>>b;
    int n = a.length();
    int m = b.length();

    min_NoOf_del_insert_toCoonvert_string_aTob(a,b,n,m);

    return 0;
}