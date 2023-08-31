#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    char numbers[n+1];
    for(int i=0; i<n; i++){
        cin>>numbers[i];
    }
    int i=0;
    // while(i<n){
    //     if(n-i>= 3){
    //         cout<<numbers[i]<<numbers[i+1]<<numbers[i+2]<<"-";
    //         i+=3;
    //     }
    //     else if(n-i==2){
    //         cout<<numbers[i]<<numbers[i+1];
    //         i+=2;
    //     }
    //     else{
    //         cout<<numbers[i]<<numbers[i+1]<<numbers[i+2];
    //         i+=3;
    //     }
    // }
    if(n%2==0){
        for(int i=0; i<n; i++){
            cout<<numbers[i];
            if(i%2!=0 && i < n-1){
                cout<<"-";
            }

        }

    }
    else{
        for(int i=0; i<3; i++){
            cout<<numbers[i];
        }
        if(n>3){
            cout<<"-";
            for(int i=3; i<n; i++){
            cout<<numbers[i];
            if(i%2==0 && i < n-1){
                cout<<"-";
            }

        }
        }
    }
   
    
    return 0;
}