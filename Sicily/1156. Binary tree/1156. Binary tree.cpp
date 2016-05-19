#include <iostream>
#include <map>
using namespace std;

struct node {
    int id, l_id, r_id;
    char letter;
     node(int _id = 0, int _l_id = 0, int _r_id = 0, char _letter = 0) :
             id(_id), l_id(_l_id), r_id(_r_id), letter(_letter) {}
};

void preorder(map<int, node>& tree, int cur) {
    if (cur == 0) {
        return;
    }
    cout << tree[cur].letter;
    preorder(tree, tree[cur].l_id);
    preorder(tree, tree[cur].r_id);
}

int main(int argc, char *argv[]) {
    int n;
    while (cin >> n) {
        int id, l_id, r_id;
        char letter;
        map<int, int> root;
        map<int, node> tree;
        for (int i = 0; i < n; i++) {
            cin >> id >> letter >> l_id >> r_id;
            node e(id, l_id, r_id, letter);
            tree[id] = e;
            ++root[id];
            --root[l_id];
            --root[r_id];
            if (root[id] == 0) root.erase(id);
            if (root[l_id] == 0) root.erase(l_id);
            if (root[r_id] == 0) root.erase(r_id);
        }
        root.erase(0);
        preorder(tree, root.begin()->first);
        cout << endl;
    }
    return 0;
}
