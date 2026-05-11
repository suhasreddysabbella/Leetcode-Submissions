class Solution {
public:

    bool canFinish(int numCourses,
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

        // Courses with no prerequisites
        for(int i = 0; i < numCourses; i++) {

            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int completed = 0;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            completed++;

            for(int neigh : adj[node]) {

                indegree[neigh]--;

                if(indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        return completed == numCourses;
    }
};