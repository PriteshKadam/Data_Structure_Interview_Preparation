#include <bits/stdc++.h> 
// Note : 
// Undirected & disconnected graph
// vertex : 0 to v-1
// edges : list of edges 
// Expected to traverse lower numbered node first

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    queue<int> bfsQueue;
    vector<bool> visitedNodes(vertex, false);
    vector<int> output;
    vector<vector<int>> adjList(vertex);

    for(pair<int, int> edge : edges) // Undirected graph
    {
        adjList[edge.first].push_back(edge.second); 
        adjList[edge.second].push_back(edge.first);
    }

    for(int node = 0 ;node < vertex; node++) // Sort node list becoz Expected to traverse lower numbered node first
    {
        sort(adjList[node].begin(), adjList[node].end());
    }

    for(int startNode = 0; startNode < vertex; startNode++) // Disconnected graph
    {
        if(visitedNodes[startNode])
        {
            continue;
        }

        bfsQueue.push(startNode);
        visitedNodes[startNode] = true;

        while(!bfsQueue.empty())
        {
            int currentNode = bfsQueue.front();
            bfsQueue.pop();
            output.push_back(currentNode);

            for(int adjNode : adjList[currentNode])
            {
                if(visitedNodes[adjNode])
                {
                    continue;
                }

                bfsQueue.push(adjNode);
                visitedNodes[adjNode] = true;

            }
        }
    }

    return output;
}