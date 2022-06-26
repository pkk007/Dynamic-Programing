#include<bits/stdc++.h>
using namespace std;

int lc_substring(string x, string y, int n, int m){
    //substring is continous in nature

    //crate a dp matrix
    int dp[n+1][m+1];
    //intialize
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
    for(int j=0; j<=m; j++)
        dp[0][j] = 0;

    //choice diagram
    int result  = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                result = max(result, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return result;
    /*last dp[n][m] return kiye and string k last m bs ek he common h substring to ans
    correct nahi aaega hume to maximum wala chahiye sare m se*/

    /* or we can traverse through whole matrix and get the maximum value because a substring can
    can exist anywhere in between so instead to returning the dp[n][m] just retunr the maximum
    value by travsersing the whole matrix*/
}

int main(){
    string x,y;
    cin>>x;
    cin>>y;
    int n = x.length();
    int m = y.length();

    cout<<"LONGEST COMMON SUBSTRING IS : "<<lc_substring(x, y, n, m);
    return 0;
}