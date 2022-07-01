#include<bits/stdc++.h>
using namespace std;

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
            if(dp[i][j-1] > dp[i-1][j]){
                s.push_back(y[j-1]);
                j--;
            }   
            else{
                s.push_back(x[i-1]);
                i--;
            }
        }
    }
    while(i>0){
        s.push_back(x[i-1]);
        i--;
    }
    while(j>0){
        s.push_back(y[j-1]);
        j--;
    }


    //return the string
    return s;
}

string print_shortest_common_superseq(string x, string y, int n, int m){
    string rev_str = lcs_table_fill(x,y,n,m);
    reverse(rev_str.begin(), rev_str.end());

    return rev_str;
}

int main(){
    string x,y;
    cin>>x;
    cin>>y;
    int n = x.length();
    int m = y.length();

    cout<<"ACTUAL SHORTEST COMMON SUPER SEQUENCE IS : "<<print_shortest_common_superseq(x,y,n,m);
    return 0;
}