#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<string> code(1000);
    vector<string> mnt;
    // int x=100;
    for(int i=0;i<200;i++){
        cin>>code[i];
    }

    for(int j=0;j<code.size();j++){
        if(code[j]=="MACRO"){
            cout<<"Macro Found at "<<j+1<<endl;
            mnt.push_back(code[j+1]);
        }
    }
    for(int k=0;k<mnt.size();k++){
        cout<<"Macro Name :"<<mnt[k]<<endl;
    }
return 0;
}