// 2056448 2009-12-13 18:19:58 Accepted  3279 C++ 400 5196 ���͵����� 

// ���ϣ��������ݽṹ�⣬��������
// �����߶������ڵ㱣�������ڵ�ͳ������
// ֧�ֵĲ���������ĳһ��λ�õ�ֵ(��Ҫ��Ҷ�ӵ�����ֵ�����µ�)��
// �Ͳ�ѯĳһ���ۻ�ͳ������λ��ֵ��
// ���帴�Ӷ� O(nlog(n))��

#include <iostream>
using namespace std;

struct TreeNode {
    int c, b, e;
    TreeNode *l, *r;
    TreeNode() : c(0), b(0), e(0), l(NULL), r(NULL) {}
} *root;

int n, q, v[100000];

int gen(TreeNode* node, int beg, int end) {
    node->b = beg;
    node->e = end;
    if(beg == end) {
        return node->c = v[beg-1];
    }
    else {
        node->l = new TreeNode();
        node->r = new TreeNode();
        return node->c = gen(node->l, beg, beg+end>>1) 
                       + gen(node->r, (beg+end>>1) + 1, end); 
    }
}

int chg(TreeNode* node, int pos, int val) {
    if(node->b == node->e) {
        int ans = val - node->c;
        node->c += ans;
        return ans;
    }
    else if(pos <= (node->b + node->e) / 2) {
        int ans = chg(node->l, pos, val);
        node->c += ans;
        return ans;
    }
    else if(pos > (node->b + node->e) / 2) {
        int ans = chg(node->r, pos, val);
        node->c += ans;
        return ans;
    }
    else {
        while(1) puts("error");
    } 
}

int qry(TreeNode* node, int rnk) {
    if(node->b == node->e) return node->b;
    else if(rnk <= node->l->c) {
        return qry(node->l, rnk);
    }
    else if(rnk > node->l->c) {
        return qry(node->r, rnk - node->l->c);
    }
    else {
        while(1) puts("error");
        return 0;
    }
}

void destroy(TreeNode* node) {
    if(!node) return;
    destroy(node->l);
    destroy(node->r);
    delete node;
}

int main() {
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", v + i);
        }
        root = new TreeNode();
        gen(root, 1, n);
        scanf("%d", &q);
        while(q--) {
            char op[2];
            scanf("%s", op);
            int x, y;
            if(*op == 'q') {
                scanf("%d", &x);
                printf("%d\n", qry(root, x));
            }
            else if(*op == 'p') {
                scanf("%d%d", &x, &y);
                chg(root, x, y);
            }
        }
        destroy(root);
    }
}
