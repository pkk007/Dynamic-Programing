#include<bits/stdc++.h>
using namespace std;

bool sos(int s[], int t, int n){
    //create a dp table
    bool dp[n+1][t+1];

    //initialization 1st row and coloum
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    
    for (int j=1; j<=t; j++)
        dp[0][j] = false;

    //choice diagram with dp optimization
    for(int i=1; i<=n; i++){
        for(int j=1; j<=t; j++){
            if(s[i-1] <= j)
                dp[i][j] = dp[i-1][j-s[i-1]] || dp[i-1][j];
            else if(s[i-1] > j)
                dp[i][j] = dp[i-1][j];
        }
    }

    //return the value
    return dp[n][t];
}

int main(){
    int s[] = { 3, 34, 4, 12, 5, 2 };
    int t= 9;
    int n = sizeof(s) / sizeof(s[0]);

    if(sos(s, t, n) == true)
        cout<<"yes subset present";
    else
        cout<<"no subset not present";

    return 0;
}
