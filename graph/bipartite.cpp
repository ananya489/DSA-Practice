#include<bits/stdc++.h>
using namespace std;

bool isBipartite(int n, vector<vector<int>>& adj){

    vector<int> color(n, -1);
    queue<int> q;

    for(int i=0;i<n;i++){
        
        if(color[i] == -1){
            q.push(i);
            color[i] = 0;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(auto it : adj[node]){
                    
                    if(color[it] == -1){
                        color[it] = 1 - color[node];
                        q.push(it);
                    }
                    
                    else if(color[it] == color[node]){
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main(){

    int n,e;
    cin>>n>>e;

    vector<vector<int>> adj(n);

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(isBipartite(n, adj))
        cout<<"Graph is Bipartite";
    else
        cout<<"Graph is Not Bipartite";

    return 0;
}