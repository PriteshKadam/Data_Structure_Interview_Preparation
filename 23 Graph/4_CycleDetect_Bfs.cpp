#include <bits/stdc++.h> 

// Note :
// Vertices labelled from 1 to vertex
//
// Logic: If during bfs we visit a already visited node and it is not the parent then cycle exist.

string cycleDetection (vector<vector<int>>& edges, int vertex, int m)
{
    // Write your code here.
    queue<int> bfsQueue;
    vector<bool> visitedNodes(vertex + vertex, false);
    vector<int> parentNodes(vertex + vertex, -1);
    vector<vector<int>> adjList(vertex + vertex);

    for(vector<int> edge : edges) // Adj List for an Undirected graph
    {
        adjList[edge[0]].push_back(edge[1]); 
        adjList[edge[1]].push_back(edge[0]);
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

            for(int adjNode : adjList[currentNode])
            {
                if(visitedNodes[adjNode])
                {
                    if(parentNodes[currentNode] != adjNode)
                    {
                        return "Yes";
                    }
                    continue;
                }

                bfsQueue.push(adjNode);
                visitedNodes[adjNode] = true;
                parentNodes[adjNode] = currentNode;

            }
        }
    }

    return "No";
}
