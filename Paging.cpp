#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,n;
    cout<<"Enter total Pages"<<endl;
    cin>>a;
    cout<<"Enter Page Size"<<endl;
    cin>>n;
    int pagehits=0;
    int pagemiss=0;
    int var=0;
    int inpt[a];
    cout<<"Enter page Sizes"<<endl;
    for(int i=0;i<a;i++){
        cin>>inpt[i];
    }
    int arr[n];
    for(int j=0;j<n;j++){
        arr[j]=inpt[j];
    }
    for(int k=n;k<a;k++){
        for(int l=0;l<n;l++){
            if(inpt[k]==arr[l]){
                pagehits+=1;
            }
        }
        if(var>n-1){
            var=0;
            arr[var]=inpt[k];
            var++;
            pagemiss+=1;
        }
        else {
            arr[var]=inpt[k];
            var++;
            pagemiss+=1;
        }
        
    }
    cout<<pagehits<<endl;
    cout<<pagemiss<<endl;

}