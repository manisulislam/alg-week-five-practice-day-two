#include<bits/stdc++.h>
using namespace std;


const int N=1e5+5;
//parent track
int parent[N];

//parentsize track
int parentSize[N];
void dsu_set(int n){
    for(int i=0; i<n; i++){
        //initially all parent are -1
        parent[i]=-1;
        //initially all parent size are 1
        parentSize[i]=1;
    }
}

//find implementation
int dsu_find(int node){
    while(parent[node]!=-1){
        node=parent[node];
    }
 return node;
}

//union implementation
void dsu_union(int a, int b){
    int leaderA= dsu_find(a);
    int leaderB= dsu_find(b);
    if(leaderA !=leaderB){
        if(parentSize[leaderA]> parentSize[leaderB]){
        //when leader A
        parent[leaderB]=leaderA;
        parentSize[leaderA]+=parentSize[leaderB];
    }
    else{
        //when leader B
        parent[leaderA]=leaderB;
        parentSize[leaderB]+=parentSize[leaderA];
    }


    }
    

}
int main(){
    int n; 
    cin>>n;
    dsu_set(n);
    vector<pair<int, int>>old_roads;
    vector<pair<int, int>>new_roads;
    for(int i=1; i<=n-1; i++){
        int a, b;
        cin>>a>>b;
        int leaderA= dsu_find(a);
        int leaderB= dsu_find(b);
        if(leaderA == leaderB) {
           
            old_roads.push_back({a,b});
             continue;
         
        }
        else{
            dsu_union(a,b);
            new_roads.push_back({leaderA, leaderB});

        }

    }
    
    // for(int i=2; i<=n; i++){
    //     if(dsu_find(1)!=dsu_find(i)){
    //         new_roads.push_back({1,i});
    //         dsu_union(1,i);
    //     }
    // }
    int d= old_roads.size();
    cout<<d<<endl;

    for( int k=0; k<d; k++){
        int i=old_roads[k].first;
        int j= old_roads[k].second;
        int u= new_roads[k].first;
        int v= new_roads[k].second;
        cout<<i<<" "<<j<<" "<<u<<" "<<v<<endl;
    }
    return 0;
}