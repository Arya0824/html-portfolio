#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter No of Jobs"<<endl;
    cin>>n;
    vector<int>jobs(n);
    for(int i=0;i<n;i++){
        cin>>jobs[i];
    }
    cout<<"Job No    "<<"Job Size  "<<"Arrival Time "<<endl;
    for(int j=0;j<n;j++){
        cout<<j+1<<"    ";
        cout<<jobs[j]<<"   ";
        cout<<j<<"   "<<endl;
    }

}