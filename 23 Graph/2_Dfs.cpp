https://www.codingninjas.com/studio/problems/dfs-traversal_630462?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Note 
// Disconnected graph
// Undirected graph

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<bool> visited(V,false);
    stack<int> dfsStack; // Contains visited nodes
    vector<vector<int>> output;

    vector<vector<int>> adjList(V);
    for(vector<int> edge : edges)
    {
        adjList[edge[0]].push_back(edge[1]); // Undirected graph
        adjList[edge[1]].push_back(edge[0]);
    }

    for(int node = 0; node < V ; node++) // Disconnected graph
    {
        if(visited[node])
        {
            continue;
        }

        dfsStack.push(node);
        visited[node] = true;
        vector<int> dfsOut;
        while(!dfsStack.empty())
        {
            int current = dfsStack.top();
            dfsStack.pop();
            dfsOut.push_back(current);
            
            for(int adjNode: adjList[current])
            {
                if(!visited[adjNode])
                {
                    dfsStack.push(adjNode);
                    visited[adjNode] = true;
                }
            }
        }

        output.push_back(dfsOut);
    }
    return output;
}