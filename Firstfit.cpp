#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;
void firstfit(vector<int> a,vector<int> b){
    cout<<"File No  "<<"File_Size  "<<"Block_No  "<<"Block Size"<<"Fragment "<<endl;
    int bindex=0;
    for(int i=0;i<a.size();i++){
        cout<<i+1<<"  ";
        cout<<a[i]<<" ";
        if(b[bindex]>=a[i]){
            cout<<bindex+1<<" ";
            cout<<b[bindex]<<" ";
            cout<<b[bindex]-a[i]<<" "<<endl;
            bindex++;
        }
        else {
            cout<<bindex+2<<" ";
            cout<<b[bindex+1]<<" ";
            cout<<b[bindex+1]-a[i]<<" "<<endl;
            bindex++;
            }
    }


}
void best_fit(vector<int> a ,vector<int> b){
    vector<int> ind;
    for(int i=0;i<b.size();i++){
        ind.push_back(b[i]);
    }
    sort(b.begin(),b.end());
    int prev;
    cout<<"File No  "<<"File_Size  "<<"Block_No  "<<"Block Size "<<"  Fragment "<<endl;
    for(int j=0;j<a.size();j++){
        for(int k=0;k<b.size();k++){
            if(b[k]>=a[j] && prev!=b[k] ){
                cout<<j+1<<" ";
                cout<<a[j]<<" ";
                
                for(int l=0;l<ind.size();l++){
                    if(b[k]==ind[l]){
                        cout<<l+1<<" ";
                        cout<<b[k]<<" ";
                        cout<<b[k]-a[j]<<" "<<endl;
                        prev=b[k];
                        break;
                       
                    }
                }
                break;
                
            

        }
    }
}
}

void worst_fit(vector<int> a, vector<int> b) {
    vector<int> ind = b;  // Keep a copy of original block sizes
    sort(b.rbegin(), b.rend());  // Sort blocks in descending order for worst fit
    int prev = -1;  // Track previously used block

    cout << "File No  " << "File_Size  " << "Block_No  " << "Block Size " << "  Fragment " << endl;
    for(int j = 0; j < a.size(); j++) {
        bool allocated = false;  // Track if the file has been allocated
        for(int k = 0; k < b.size(); k++) {
            if(b[k] >= a[j] && prev != b[k]) {  // Check if block can fit the file
                cout << j+1 << " " << a[j] << " ";
                
                // Find original block index
                for(int l = 0; l < ind.size(); l++) {
                    if(b[k] == ind[l]) {
                        cout << l+1 << " " << b[k] << " " << b[k] - a[j] << endl;
                        prev = b[k];  // Mark this block as used
                        allocated = true;
                        break;
                    }
                }
                if(allocated) break;
            }
        }
        if(!allocated)  // If no block could be allocated
            cout << j+1 << " " << a[j] << " Not Allocated" << endl;
    }
}


int main(){
    int blocks=4;
    int files=3;
    vector<int>file_size(3);
    vector<int>block_size(4);
    
    cout << "Enter file sizes: ";
    for(int i=0;i<3;i++){
        cin>>file_size[i];
    }
    
    cout << "Enter block sizes: ";
    for(int j=0;j<4;j++){
        cin>>block_size[j];
    }

    //firstfit(file_size,block_size);
    best_fit(file_size,block_size);
}