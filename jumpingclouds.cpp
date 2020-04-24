#include<iostream>
using namespace std;
int main(){
// cout<<"\n\n";

int size;
cin>>size;

int arr[size];
for(int i=0;i<size;i++)
    cin>>arr[i];

int currindex=0;
int jump=0;

for(int i=0;i<size;i++){
// while(currindex<=size-1){

if(currindex==size-1)
    break;


    if(arr[currindex+2]==0){
        jump++;
        currindex+=2;        
    }
    else if(arr[currindex+1]==0){
        jump++;
        currindex+=1;
    }

cout<<"\n\nprinting cuurent index "<<currindex<<"\n\n";
}

// }
cout<<"\n printing jumps "<<jump;
// cout<<jump;/
// cout<<"\n\n";
return 0;
}