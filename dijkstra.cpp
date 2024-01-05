#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int INF=1e9+10;
vector<pair<int,int>>graph[N];
vector<int>vis(N,0);
vector<int>dist(N,INF);


// directed graph minimum distance  algorithm
void dijkstra(int source){
    // vector<int>vis(N,0);
    // vector<int>dist(N,INF);
    set<pair<int,int>>st;
    st.insert({0,source});
    dist[source]=0;
    while(st.size()>0){
        auto node=*st.begin();
        int v=node.second;
        int vDist=node.first;
        st.erase(st.begin());
        // if(vis[v]) continue;
        // vis[v]=1;

        for(auto child: graph[v]){
            int cNode=child.first;
            int wt=child.second;
            if(dist[v]+wt<dist[cNode]){
                dist[cNode]=dist[v]+wt;
                st.insert({dist[cNode],cNode});
            }
        }
    }
    // for(int i=1; i<=6; i++){
    //     cout<<"distance from 1 to "<<i<< " "<<dist[i]<<endl;
    // }

    return;

}


int main(){
    int vrtx,edge;
    cin>>vrtx>>edge;
    
    for(int i=0; i<edge; i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        graph[x].push_back({y,wt});
        graph[y].push_back({x,wt});
    }
    dijkstra(1);
   for(int i=1; i<=vrtx; i++){
        cout<<"distance from 1 to "<<i<< " "<<dist[i]<<endl;
    }

    
    return 0;
}