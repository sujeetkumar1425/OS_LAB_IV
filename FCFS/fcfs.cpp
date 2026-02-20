#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,A_T,B_T,C_T,T_A_T,W_T;
    cout<<"Enter no of processe:"<<endl;
    cin>>n;
    vector<int>A_T(n);
    vector<int>B_T(n);
    vector<int>C_T(n);
    vector<int>T_A_T(n);
    vector<int>W_T(n);
    for(int i=0;i<n;i++){
        if(A_T[i]==0){
            C_T[i]=A_T[i]+B_T[i];
        }
    }

    
}
