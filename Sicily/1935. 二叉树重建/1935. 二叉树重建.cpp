#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct node {
    char ch;
    node *l, *r;
    node(char c) : ch(c), l(NULL), r(NULL) {}
};

node* build(string& pre, int s1, int e1, string& in, int s2, int e2) {
    if (s1 > e1) {
        return NULL;
    }
    node* p = new node(pre[s1]);
    // leaf
    if (s1 == e1) {
        return p;
    }
    // find root
    int pos = 0;
    for (int i = s2; i <= e2; i++) {
        if (in[i] == pre[s1]) {
            pos = i;
            break;
        }
    }
    p->l = build(pre, s1 + 1, s1 + (pos - s2), in, s2, pos - 1);
    p->r = build(pre, s1 + (pos - s2) + 1, e1, in, pos + 1, e2);
    return p;
}

void release(node* root) {
    if (root == NULL) {
        return;
    }
    release(root->l);
    release(root->r);
    delete root;
}

void bfs(node* p) {
    queue<node*> q;
    q.push(p);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        cout << temp->ch;
        if (temp->l) {
            q.push(temp->l);
        }
        if (temp->r) {
            q.push(temp->r);
        }
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    while (n--) {
        string pre, in;
        cin >> pre >> in;
        int size = pre.size();
        node* root = build(pre, 0, size - 1, in, 0, size - 1);
        bfs(root);
        release(root);
    }
    return 0;
}
