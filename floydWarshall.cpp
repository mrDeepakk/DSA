#include<bits/stdc++.h>
using namespace std;

const int N=100;
const int INF=1e4+10;

int dist[N][N];


int main(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j) dist[i][j]=0;
            else
                dist[i][j]=INF;
        }
    }
    int vrtx,edge;
    cin>>vrtx>>edge;

    

    for(int i=0; i<edge; i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        dist[x][y]=wt;
        dist[y][x]=wt;
    }

    for(int k=1; k<=vrtx; k++){
        for(int i=1; i<=vrtx; i++){
            for(int j=1; j<=vrtx; j++){
                if(dist[i][k]!=INF && dist[k][j]!=INF)
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i=1; i<=vrtx; i++){
        for(int j=1; j<=vrtx; j++){
            if(dist[i][j]==INF)
                cout<<"I ";
            else
                cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}