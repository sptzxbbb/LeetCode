// DFS Solution
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int> > graph(numCourses, vector<int>(0));
        vector<bool> visit(numCourses, false);
        vector<bool> deal(numCourses, false);
        for (auto a : prerequisites) {
            graph[a.second].push_back(a.first);
        }
        for (int i = 0; i < numCourses; i++) {
            if (deal[i] == false && !DFS(graph, visit, deal, i)) {
                return false;
            }
        }
        return true;
    }
    // starting from node i, if no loop is found return true; otherwise, false.
    bool DFS(vector<vector<int> >& graph, vector<bool>& visit, vector<bool>& deal, int i) {
        if (visit[i] == true) {
            return false;
        }
        visit[i] = true;
        for (auto a : graph[i]) {
            if (!DFS(graph, visit, deal, a)) {
                return false;
            }
        }
        deal[i] = true;
        visit[i] = false;
        return true;
    }
};