#include <bits/stdc++.h>
using namespace std;

int mcm(int dimension_array[], int i, int j)
{
    // base condition
    if (i >= j)
        return 0;

    int min = INT_MAX;
    int temp_ans;
    for (int k=i; k<=j-1; k++){
        temp_ans = mcm(dimension_array, i, k) + mcm(dimension_array, k+1, j) + dimension_array[i-1]*dimension_array[k]*dimension_array[j];

        if(temp_ans < min)
            min = temp_ans;
    }
    return min;
}

int main(){
    int dimension_array[] = {10,30,5,60};
    int n = sizeof(dimension_array)/sizeof(dimension_array[0]);

    cout<<"MINMUM NUMBER OF MULTIPICATION OPRATION IS : "<<mcm(dimension_array, 1, n-1);

    return 0;
}