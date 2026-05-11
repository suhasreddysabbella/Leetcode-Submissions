class Solution {
public:

    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        vector<int> indegree(numCourses, 0);

        // Build graph
        for(auto &p : prerequisites) {

            int a = p[0];
            int b = p[1];

            adj[b].push_back(a);

            indegree[a]++;
        }

        queue<int> q;

        // Push all courses with indegree 0
        for(int i = 0; i < numCourses; i++) {

            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            order.push_back(node);

            for(int neigh : adj[node]) {

                indegree[neigh]--;

                if(indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        // Cycle exists
        if(order.size() != numCourses) {
            return {};
        }

        return order;
    }
};