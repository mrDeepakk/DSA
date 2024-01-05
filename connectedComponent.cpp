#include <bits/stdc++.h>
using namespace std;
const int n=1e3+7;
vector<int>graph[n];
bool vist[n];
vector<vector<int>>connectedComp;
vector<int>temp;

bool dfs(int vertex,int par){
    bool isloop=false;

    vist[vertex]=true;     //visit and mark true
    // temp.push_back(vertex);
    for(int child: graph[vertex]){
        if(vist[child] && child==par) continue;

        if(vist[child]) return true;

        isloop |= dfs(child,vertex);

    }
    return isloop;
}


int main() {
	int vertex,edge;
    cin>>vertex>>edge;
	for(int i=0; i<edge; i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
	}
    int count=0;

    // for(int i=1; i<=vertex; i++){
    //     if(vist[i]) continue;
    //     temp.clear();
    //     dfs(i,0);
    //     connectedComp.push_back(temp);
    //     // count++;
    // }

    // check is loop or not
    int flag=0;
    for(int i=1; i<=vertex; i++){
        if(vist[i]) continue;
        if(dfs(i,0)){
            cout<<"loop exist in this graph"<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"loop is not exist in this graph"<<endl;
    }

    // print connectedComp 
    // for(auto comp: connectedComp){
    //     for(int it: comp){
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }
  

	
	return 0;
}