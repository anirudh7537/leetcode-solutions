class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Step 1: Build the Adjacency List and globally track in-degrees
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        vector<bool> suspicious(n, false);
        
        for (auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v); // u invokes v
            inDegree[v]++;       // v has an incoming edge
        }
        
        // Step 2: BFS Traversal starting from the buggy node 'k'
        queue<int> q;
        q.push(k);
        suspicious[k] = true; // Mark 'k' as suspicious immediately
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            // Traverse all methods called by the current suspicious method
            for (int neighbor : adj[curr]) {
                // Since this edge is internal (suspicious to suspicious),
                // we decrement the neighbor's in-degree.
                inDegree[neighbor]--; 
                
                // If we haven't visited this neighbor yet, mark and queue it
                if (!suspicious[neighbor]) {
                    suspicious[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        // Step 3: Validate if the suspicious group is safe to remove
        bool cannotRemove = false;
        for (int i = 0; i < n; i++) {
            // If a node is suspicious BUT still has a remaining in-degree > 0,
            // it means a healthy node outside the group depends on it!
            if (suspicious[i] && inDegree[i] > 0) {
                cannotRemove = true;
                break;
            }
        }
        
        // Step 4: Construct the final result
        vector<int> result;
        if (cannotRemove) {
            // We can't remove anything, so return the original methods [0 to n-1]
            for (int i = 0; i < n; i++) {
                result.push_back(i);
            }
        } else {
            // It's safe to remove! Only add healthy (non-suspicious) nodes to result
            for (int i = 0; i < n; i++) {
                if (!suspicious[i]) {
                    result.push_back(i);
                }
            }
        }
        
        return result;
    }
};