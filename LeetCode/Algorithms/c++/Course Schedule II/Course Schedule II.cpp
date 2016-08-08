class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int> > graph(numCourses, vector<int>());
        vector<int> inDegree(numCourses, 0);
        for (auto i : prerequisites) {
            graph[i.second].push_back(i.first);
            ++inDegree[i.first];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> res;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (auto i : graph[node]) {
                --inDegree[i];
                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        if (res.size() != numCourses) {
            res.clear();
        }
        return res;
    }
};