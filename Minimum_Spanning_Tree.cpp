#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
//parent track
int parent[N];

//bool visited
bool visited[N];
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

//class Edge
class Edge{
    public:
    int i, j, k;
    Edge(int i, int j, int k){
        this->i=i;
        this->j=j;
        this->k=k;
    }
};

//boolean function
bool cmp(Edge a, Edge b){
    return a.k < b.k;
}
int main(){
    int n,m;
    cin>>n>>m;
    dsu_set(n);
    vector<Edge>v;
    vector<Edge>ans;
    while(m--){
        int i, j, k;
        cin>>i>>j>>k;
        v.push_back(Edge(i,j,k));
    }

    sort(v.begin(), v.end(), cmp);

    for(Edge val: v){
        int i= val.i;
        int j= val.j;
        int k= val.k;
        int leaderA= dsu_find(i);
        int leaderB= dsu_find(j);
        if(leaderA == leaderB) continue;
        ans.push_back(val);
        dsu_union(i,j);
    }

    long long sum=0;

    for(Edge val : ans){
        sum+=(long long)(val.k);
    }

    cout<<sum<<endl;
    return 0;
}