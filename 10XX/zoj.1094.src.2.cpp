// POJ AC
// ��������������õ����
// ZOJ �����ݲ�һ���������������ǰ����ÿ��������������ס�����ڵ�
// Ҳ���ǲ����� (ABC) ���������ZOJ �Ĺ��ƾ�����������
// Ҫ�ı佨����ʽ�����ܹ� ZOJ 

#include <iostream>
using namespace std;

struct Node {
    Node( Node* p = NULL, int x = 0, int y = 0 ) : 
        parent(p), x(x), y(y), left(NULL), right(0) {}
    int     x,  y;
    Node*   parent;
    Node*   left;
    Node*   right;
};

inline bool isLeaf( Node* const ptr ) {
    return ptr -> left == NULL && ptr -> right == NULL;
}

int eval( Node* const ptr ) {
    // ��/�Ҷ��ӵ��ۼӳ˷����� 
    int     cntLeft = 0,  cntRight = 0;
    // �������Ӳ���Ҷ��
    if( !isLeaf( ptr -> left ) )
        cntLeft = eval( ptr -> left );
    // ����Ҷ��Ӳ���Ҷ��
    if( !isLeaf( ptr -> right ) )
        cntRight = eval( ptr -> right );
    // ������ 
    ptr -> x = ptr -> left  -> x;
    ptr -> y = ptr -> right -> y;
    int     ans = ( ptr -> left -> y == ptr -> right -> x ) ?
                  ( ptr -> x * ptr -> right -> x * ptr -> y ) : -1;
    delete  ptr -> left;
    delete  ptr -> right;
    ptr -> left = NULL;
    ptr -> right= NULL;
    
    if( cntLeft < 0 || cntRight < 0 || ans < 0 )
        return  -1;
    else
        return  ans + cntLeft + cntRight;
}

void postOrder(Node*root){
    if(root){ postOrder(root->left);
    postOrder(root->right);
        cout<< root -> x<<' '<< root -> y<<endl;
    }
}

int main() {
    
    int     X[26] = {};
    int     Y[26] = {};
    int     N;
    char    C;
    
    cin >> N;
    while( N-- )
        cin >> C >> X[C-'A'] >> Y[C-'A'];

    string  oper;
    Node*   root;
    Node*   current;
    
    while( cin >> oper ) {
        
        if( oper.length() == 1 ) {
            cout << 0 << endl;
            continue;
        }
        
        current = root = new  Node();
        
        for( int i = 0; i < oper.length() - 1; i++ ) {
            switch( oper[i] ) {
                // �����µĶ��ӽڵ㣬��ת������ӽڵ� 
                case '(':
                    current -> left = new Node( current );
                    current -> right = new Node( current );
                    current = current -> left;
                break;
                
                // �ص����ڵ㣬ʹ�ø��ڵ���ֵ 
                case ')':
                    current = current -> parent;
                    // ������ڵ�������ӣ���ת���ҽڵ� 
                    if( current == current -> parent -> left )
                        current = current -> parent -> right;
                break;
                
                // ��ø�ֵ 
                default:
                    current -> x = X[ oper[i] - 'A' ];
                    current -> y = Y[ oper[i] - 'A' ];
                    // �������ڵ㣬��ֵ��ת���ҽڵ� 
                    if( current == current -> parent -> left )
                        current = current -> parent -> right;
            }
        }
        int     value = eval( root );
        delete  root;
        if( value < 0 )
            cout << "error" << endl;
        else
            cout << value << endl;
    }
    
}
