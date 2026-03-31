#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>& adj,
         vector<int>& visited, vector<int>& pathVisited){

    visited[node] = 1;
    pathVisited[node] = 1;

    for(auto it : adj[node]){
        if(!visited[it]){
            if(dfs(it, adj, visited, pathVisited))
                return true;
        }
        else if(pathVisited[it]){
            return true;
        }
    }

    pathVisited[node] = 0;
    return false;
}

bool isCycle(int n, vector<vector<int>>& adj){

    vector<int> visited(n,0);
    vector<int> pathVisited(n,0);

    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(dfs(i, adj, visited, pathVisited))
                return true;
        }
    }
    return false;
}

int main(){

    int n,e;
    cin>>n>>e;

    vector<vector<int>> adj(n);

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

    if(isCycle(n,adj))
        cout<<"Cycle Detected";
    else
        cout<<"No Cycle";

    return 0;
}