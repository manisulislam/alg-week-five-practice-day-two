#include<bits/stdc++.h>
using namespace std;


const int N=1e5+5;

//boolean visited
bool visited[N];
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

//Edge class;
class Edge{
    public: 
    int a,b,w;
    Edge(int a, int b, int w){
        this->a=a;
        this->b=b;
        this->w=w;
    }
};

bool cmp(Edge a, Edge b){
    return a.w < b.w;
}
int main(){
    int n, e;
    cin>>n>>e;
    vector<Edge>v;
    vector<Edge>ans;
    dsu_set(n);
    while (e--)
    {
        int b,e,w;
        cin>>b>>e>>w;
        v.push_back(Edge(b,e,w));
       
    }
    
    sort(v.begin(), v.end(), cmp);

    for(Edge val: v){
        int b= val.a;
        int e=val.b;
        int w= val.w;
        int leaderA= dsu_find(b);
        int leaderB= dsu_find(e);
        if(leaderA == leaderB) continue;
        ans.push_back(val);
        dsu_union(b,e);

    }

    long long sum=0;

    for(Edge val: ans){
        sum+=(long long)(val.w);

    }
    
    cout<<sum<<endl;

    return 0;
}