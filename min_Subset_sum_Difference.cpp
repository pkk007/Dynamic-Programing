#include<bits/stdc++.h>
using namespace std;

vector<int> sos(int s[], int t, int n){
    //create a dp matrix
    bool dp[n+1][t+1];

    //intialize
    for(int j=0; j<=t; j++)
        dp[0][j] = false;
    for(int i=0; i<=n; i++)
        dp[i][0] = true;

    //fill the matrix
    for(int i=1; i<=n; i++){
        for(int j=1; j<=t; j++){
            if(s[i-1] <= j)
                dp[i][j] = dp[i-1][j-s[i-1]] || dp[i-1][j];
            else if(s[i-1] > j)
                dp[i][j] = dp[i-1][j];
        }
    }

    //store the last row in vetor
    vector<int> v;
    for(int j=0; j<=t/2; j++){
        if(dp[n][j] == true)
            v.push_back(j);
    }

    //return the final vector have the possible sum till RANGE/2
    return v;
}

int minSubsetSumDifference(int s[], int range, int n){
    vector<int> v = sos( s, range, n);

    int min_value = INT_MAX;
    for(int i=0; i<v.size(); i++)
        min_value = min(min_value, range-2*v[i]);

    //return the min sum difference of the subset
    return min_value;
}

int main(){
    int s[] = {1,6,11,5};
    int n = sizeof(s)/sizeof(s[0]);
    int range = 0;
    for(int i=0; i<n; i++)
        range = range + s[i];
    int ans = minSubsetSumDifference(s, range, n);

    cout<<"MINIMUM SUM DIFFERENCE OF THE SUBSET = "<<ans;

    return 0;
}