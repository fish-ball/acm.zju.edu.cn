// 1796610 2009-03-21 15:04:30 Accepted  2684 C++ 0 184 ���͵����� 

// ����һ�����������ڵ�Ҫô��Ҷ�ӣ�Ҫô���������ӡ�
// �����Ҹ����������ڶ���֮���·�����ȣ�Ȼ����һ�β�ѯ��
// �������������֮���·���ж೤�� 
// ���ݸ�����ϵ���ɹ����������������Ȼ�� O(N) ������������ȼ��ɡ� 

// ���幹�췽����������һ���ڵ㣬Ȼ�������һ���뵱ǰ�ڵ����Ϊ d
// ���ߵ�һ�����򸸽ڵ���һ����������ڵ�û�ж��壬����һ����
// Ȼ����ʣ�µ� d-1 �������������ȼ��ߣ���->��->���ڵ㣻 
// ���� d-1 ��֮�󵽴�Ľڵ㼴Ϊ�µ�Ҷ�ӡ�
// �������ַ������������������������������

// �ڶ�����������������ȣ������ѯ�������ڵ�Ϊ x �� y�� 
// ��һ�� map ���ָ���һ�� int���� x ���ݵ�����
// ��;ÿһ���ڵ� x' ��ָ��͵� x ��·�� xi ���Ž� map �С�
// Ȼ��� y ���ݵ�������ÿһ���������Ľڵ� y'�������Ƿ��� map �С�
// ����ڣ������Ϊ��ǰ y' �� y ��·���� yi + MAP[y']��

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    Node* parent;
    Node() : left(NULL), right(NULL), parent(NULL) {}
};

int T, N;

Node* current;

vector<Node*> all, leaves;

map<Node*, int> path;

int main() {
    for(cin >> T; T--;) {
        cin >> N;
        current = new Node();
        all.push_back(current);
        leaves.push_back(current);
        for(int i = 1, d; i < N; ++i) {
            cin >> d;
            if(current->parent == NULL) {
                current->parent = new Node();
                current->parent->left = current;
                all.push_back(current->parent);
            }
            current = current->parent;
            for(int j = 1; j < d; ++j) {
                if(current->left == NULL) {
                    current->left = new Node();
                    current->left->parent = current;
                    all.push_back(current->left);
                    current = current->left;
                }
                else if(current->right == NULL) {
                    current->right = new Node();
                    current->right->parent = current;
                    all.push_back(current->right);
                    current = current->right;
                }
                else {
                    if(current->parent == NULL) {
                        current->parent = new Node();
                        current->parent->left = current;
                        all.push_back(current->parent);
                    }
                    current = current->parent;
                }
            }
            leaves.push_back(current);
        }
        int x, y, ans;
        cin >> x >> y;
        path.clear();
        current = leaves[x - 1];
        for(int i = 1; current->parent != NULL; ++i) {
            path[current->parent] = i;
            current = current->parent;
        }
        current = leaves[y - 1];
        for(int i = 1; current->parent != NULL; ++i) {
            if(path.find(current->parent) != path.end()) {
                ans = i + path[current->parent];
                break;
            }
            current = current->parent;
        }
        cout << ans << endl;
        for(int i = 0; i < all.size(); ++i)
            delete all[i];
        all.clear();
        leaves.clear();
    }
}
