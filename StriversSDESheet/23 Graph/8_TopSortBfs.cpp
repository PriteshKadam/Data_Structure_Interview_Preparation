//https://www.codingninjas.com/studio/problems/982938?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h> 
// Note :
// DAG : Directed acyclic graph
// No multiple edges , self loops
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here

    vector<int> indegree(v, 0); // indegree = number of incoming edges
    vector<vector<int>> adjList(v, vector<int>());
    queue<int> bfsqueue;
    vector<int> output;

    // calc indegrees and adj list
    for(auto edge : edges)
    {
        adjList[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++;
    }

    // push starting nodes = nodes with indegree 0
    for(int node = 0; node < indegree.size(); node++)
    {
        if(indegree[node] == 0)
        {
            bfsqueue.push(node);
        }
    }

    while(!bfsqueue.empty())
    {
        int current = bfsqueue.front();
        bfsqueue.pop();
        output.push_back(current);
        for(int adjNode : adjList[current])
        {
            indegree[adjNode]--;
            if(indegree[adjNode] == 0)
            {
                bfsqueue.push(adjNode);
            }
        }
    }

    return output;
}