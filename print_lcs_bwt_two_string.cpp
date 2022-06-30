#include<bits/stdc++.h>
using namespace std;

//for printing lcs we have to traverse backward

string lcs_table_fill(string x, string y, int n, int m){
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

    //print the LCS
    string s = " ";
    int i=n;
    int j=m;
    while(i>0 && j>0){
        if(x[i-1] == y[j-1]){
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i][j-1] > dp[i-1][j])
                j--;
            else
                i--;
        }
    }

    //return the string
    return s;
}

string print_lcs(string x, string y, int n, int m){
    //we get the string in reverse order
    string rev_string = lcs_table_fill(x, y, n ,m);

    reverse(rev_string.begin(), rev_string.end());
    return rev_string;
}

int main(){
    string x,y;
    cin>>x;
    cin>>y;
    int n = x.length();
    int m = y.length();

    cout<<"ACTUAL LONGEST COMMON SUBSEQUENCE IS : "<<print_lcs(x, y, n, m);
    return 0;
}