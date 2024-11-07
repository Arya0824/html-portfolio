#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter no of Jobs"<<endl;
    cin>>n;

    vector<int>jobs(n);
    vector<int>Bt(n);
    
    for(int i=0;i<n;i++){
        cin>>jobs[i];
        cin>>Bt[i];
        
    }
    vector<int> ind(n);
    for(int p=0;p<n;p++){
        ind.push_back(jobs[p]);
    }
    int jobcount=2;
    sort(jobs.begin(),jobs.end());
    cout<<"Job No "<<"Job Size "<<"Arrival Time "<<"Burst Time"<<endl;
    cout<<"1    "<<ind[0]<<"   "<<"0    "<<Bt[0]<<endl;
    for(int m=0;m<n;m++){
        if(jobs[m]!=ind[0]){
            cout<<jobcount<<"    "<<jobs[m]<<"    "<<jobcount-1<<"    "<<Bt[jobcount-1]<<endl;
            jobcount+=1;
        }
    }
    return 0;


}