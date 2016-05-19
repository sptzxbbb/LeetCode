#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct employee {
    int id, salary, height, father_id, num_sub;

    employee(int _id, int _salary, int _height, int _father_id = -1, int _num_sub = 0) :
            id(_id), salary(_salary), height(_height), father_id(_father_id), num_sub(_num_sub) {}
};

bool cmp(employee e1, employee e2) {
    return e1.salary < e2.salary;
}

/*
  1. 按薪水升序排序
  2. 从左到右扫描, 确定每个Employee的immdediate boss, 记录father_id(数组中的索引), 同时immediate Boss的num_sub加1.
  3. 根据Query, 遍历查询ID, 输出immediate的id以及num_sub.
 */

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    while (n--) {
        int m, q;
        cin >> m >> q;
        vector<employee> v;
        int id, salary, height;
        for (int i = 0; i < m; i++) {
            cin >> id >> salary >> height;
            employee e(id, salary, height);
            v.push_back(e);
        }
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < m; ++i) {
            int index = -1;
            for (int j = i + 1; j < m; j++) {
                if (v[j].height >= v[i].height) {
                    index = j;
                    break;
                }
            }
            if (index != -1) {
                v[i].father_id = index;
                v[index].num_sub += v[i].num_sub + 1;
            }
        }
        vector<int> query(q);
        for (int i = 0; i < q; i++) {
            cin >> query[i];
        }
        for (int i = 0; i < q; i++) {
            for (int j = 0; j < m; j++) {
                if (v[j].id == query[i]) {
                    if (v[j].father_id != -1) {
                        cout << v[v[j].father_id].id;
                    } else {
                        cout << 0;
                    }
                    cout << ' ' << v[j].num_sub << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
