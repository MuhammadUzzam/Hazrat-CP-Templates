//Bismillah
/*
Kahn's Algorithm (Topological Sort)
Works for Directed Graph

Returns:
- Topological ordering if graph is DAG.
- {} if cycle exists.
*/

vector<int> topo_sort(int n, vector<vector<int>> &g){
    vector<int> indegree(n + 1, 0);

    // Calculate indegrees
    for(int u = 1; u <= n; ++u){
        for(int v : g[u])
        indegree[v]++;
    }
    
    // Agar lexicographically smallest topological order chahiye
    // priority_queue<int, vector<int>, greater<int>> q;
    queue<int> q;

    // Push all nodes with indegree 0
    for(int i = 1; i <= n; ++i){
        if(indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        topo.push_back(u);

        for(int v : g[u]){
            indegree[v]--;

            if(indegree[v] == 0)
                q.push(v);
        }
    }

    // Cycle exists
    if((int)topo.size() != n)
        return {};

    return topo;
}
