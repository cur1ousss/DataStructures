#include<iostream>
using namespace std;
int main(){
// cout<<"\n\n";

int size;
cin>>size;
long int target;
cin>>target;


long long int arr[size];

int pairs=0;

for(int i=0;i<size;i++)
    cin>>arr[i];

  for(int i=0;i<size;i++){
      for(int j=0;j<size;j++){

          if(j==2*i){
              break;
          }

          if(arr[j]==arr[i]+target){
              pairs++;
          }
      }
  }  

cout<<pairs;
// cout<<"\n\n";
return 0;
}