// Same as check bipartite graph. 
// odd length cycle -> no bipartition -> tough to implement
// graph coloring and bfs -> color graph in 2 color if possible then bipartite

class Solution {
public:
    bool isBipartite = true;
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjList(n+1);
        
        for(auto ele : dislikes)
        {
            adjList[ele[0]].push_back(ele[1]);
            adjList[ele[1]].push_back(ele[0]);
            
        }
        
        queue<int> q;
        vector<int> visited(n+1, -1);
        
        for(int i=1; i<=n; ++i)
        {
            if(visited[i] == -1)
            {
                q.push(i);
                visited[i] = 0;
                
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    
                    for(auto nxt : adjList[node])
                    {
                        if(visited[nxt] == -1)
                        {
                            visited[nxt] = visited[node] ^ 1;
                            q.push(nxt);
                        }
                        else {
                            isBipartite &= visited[node] != visited[nxt];
                        }
                    }
                        
                }
            }
        }
        
        return isBipartite;
    }
};