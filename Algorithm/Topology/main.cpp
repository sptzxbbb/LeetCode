#include "iostream"
#include "vector"
#include "list"
using namespace std;

struct node {
    int indegree;
	vector<int> after;
};

list<int> f;

void add(node* v, int n, bool* vis, int temp) {
	vis[temp] = true;
	for (int i = 0; i < v[temp].after.size(); ++i) {
		--v[v[temp].after[i]].indegree;
		if (0 == v[v[temp].after[i]].indegree) {
			f.push_back(v[temp].after[i]);
		}
	}
}

void restore(node* v, int n, bool* vis, int temp) {
	vis[temp] = false;
	for (int i = 0; i < v[temp].after.size(); ++i) {
		++v[v[temp].after[i]].indegree;
		if (1 == v[v[temp].after[i]].indegree) {
			f.pop_back();
		}
	}
}

void Topology(node* v, int n, bool* vis) {
	if (!f.size()) {
		cout << endl;
		return;
	}
	
	int size = f.size();
	for (int i = 0; i < size; ++i) {
		int temp = f.front();
		cout << temp;
		f.pop_front();
		add(v, n, vis, temp);
		Topology(v, n, vis);
		restore(v, n, vis, temp);
		f.push_back(temp);
	}

}


int main(int argc, char *argv[]) {
    int n, m;
	cin >> n >> m;

	node v[n];
	//  init
	for (int i = 0; i < n; ++i) {
		v[i].indegree = 0;
	}

	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		v[a].after.push_back(b);
		++v[b].indegree;
	}

	bool vis[n];
	for (int i = 0; i < n; ++i) {
		if (v[i].indegree == 0) {
			f.push_back(i);
		}
		vis[i] = false; 
	}

	Topology(v, n , vis);

    return 0;
}

