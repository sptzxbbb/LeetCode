struct node {
    int val;
    int indegree;
    set<int> post;
    node() : val(0), indegree(0) {}
}

class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        node courses[numCourses];
        bool visit[numCourses] = {false};
        pair<int, int> e;
        int size = prerequisites.size();
        for (int i = 0; i < size; i++) {
            e = prerequisites[i];
            ++courses[e->first].indegree;
            courses[e->second].post.insert(e->first);
        }

        vector<int> ans;
        int count = 0;
        while (count != numCourses) {
            bool find = false;
            for (int i = 0; i < size; i++) {
                if (visit[i] == false && courses[i].indegree == 0) {
                    ++count;
                    ans.push_back(i);
                    auto it = post.begin();
                    while (it != post.end()) {
                        --course[(*it)].indegree;
                        ++it;
                    }
                }
            }
            if (!find) {
                ans.clear();
                return ans;
            }
        }
        return ans;
    }
}