// 2002763 2009-09-26 09:56:30 Accepted  1700 C++ 0 184 ���͵����� 
// ���������������Ĳ��ɾҶ���У��������������
// ���պ�ɾ���Ȳ��뷽ʽ���������������Ȼ�����������ɡ� 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    char c;
    Node(char c = '\0') : c(c), left(NULL), right(NULL) {}
} *root;

void insert(Node* &p, char c) {
    if(!p) {
        p = new Node(c);
    }
    else if(c < p->c) {
        insert(p->left, c);
    }
    else {
        insert(p->right, c);
    }
}

void destroy(Node* p) {
    if(!p) return;
    destroy(p->left);
    destroy(p->right);
    delete p;
}

void output(Node* p) {
    if(!p) return;
    putchar(p->c);
    output(p->left);
    output(p->right);
}

int main() {
    vector<string> V;
    string buf = "*";
    while(buf != "$") {
        V.clear();
        while(cin >> buf && isalpha(buf[0])) {
            V.push_back(buf);
        }
        destroy(root);
        root = NULL;
        for(int k = V.size() - 1; k >= 0; --k) {
            for(int i = 0; i < V[k].size(); ++i) {
                insert(root, V[k][i]);
            }
        }
        output(root);
        puts("");
    }
}

