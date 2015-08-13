class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<int> inDegree(numCourses);
        vector<vector<int> > graph(numCourses, vector<int>(0));
        for (auto a : prerequisites) {
            graph[a.second].push_back(a.first);
            ++inDegree[a.first];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (0 == inDegree[i]) {
                q.push(i);
            }
        }
        while (q.size()) {
            int t = q.front();
            q.pop();
            for (auto a : graph[t]) {
                --inDegree[a];
                if (0 == inDegree[a]) {
                    q.push(a);
                }
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (0 != inDegree[i]) {
                return false;
            }
        }
        return true;
    }
};