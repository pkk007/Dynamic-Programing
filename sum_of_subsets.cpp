#include<bits/stdc++.h>
using namespace std;

int sos(int s[], int t, int n){
    //base condition
    if(t==0)
        return 1;
    if(n==0 && t>0)
        return 0;

    //choice diagram
    if(s[n-1] <= t)
        return sos(s, t-s[n-1], n-1) || sos(s, t, n-1); //element ko include krke yaa na krke sum tagert k baraber aaya yaa nahi
    else if(s[n-1] > t)
        return sos(s, t, n-1);
}

int main(){

    int s[] = {2,3,8,10};
    int t = 14;
    int n = sizeof(s)/sizeof(s[0]);
    int ans = sos(s, t, n);
    if(ans)
        cout<<"yes subset present";
    else
        cout<<"no subset not present";

    return 0;
}