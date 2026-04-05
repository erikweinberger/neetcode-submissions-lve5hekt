class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> edgeConnections(numCourses);

        for (const auto & pr : prerequisites) {
            edgeConnections[pr[1]].push_back(pr[0]);
        }
        
        std::vector<bool> visited(numCourses, false);
        std::vector<int> parents(numCourses);
        for (int i = 0; i < numCourses; ++i) {
            parents[i] = i;
        }

        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
               if (detectCycle(i, i, edgeConnections, parents, visited)) return false; 
            }
        }

        return true;
        
    }

    bool detectCycle(int node, int parent, const std::vector<std::vector<int>>& edgeConnections, std::vector<int>& parents, std::vector<bool>& visited) {
        visited[node] = 0;
        int prevparent = parents[node];
        parents[node] = parent;

        for (const int ec : edgeConnections[node]) {
            if (parent == parents[ec]) return true;

            if (!visited[ec]) {
               if (detectCycle(ec, parent, edgeConnections, parents, visited)) return true;
            }
        }

        parents[node] = prevparent;

        return false;
    }
};
