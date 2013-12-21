// 2887682 2008-05-03 22:04:08 Accepted 1944 C++ 00:00.00 836K ���͵����� 

// ��֪����ǰ�����Լ������ţ��������
// �ݹ������� str = inorder��
// ���ҳ� preorder �е�����Ĵ����� str �е��ַ�
// ����ַ���Ȼ��ʣ����������ĩ��
// �����ַ�ѹ����򴮣��� preorder �б��Ϊ 0
// Ȼ���� str Ϊ inorder �ղ����Ԫ�ص����������ݹ����
// �� str Ϊ inorder �ղ������Ԫ�ص����������ݹ����
// ���õ��� postorder ����Ϊ���� 

#include <string>
#include <iostream>
using namespace std;

string  pre, in, post;

void getPost( const int& left, const int& right ) {
    
    if( left == right ) return;
    
    int middle;
    for( int i = 0; i < pre.size(); ++i ) {
        if( pre[i] ) {
            middle = -1;
            for( int j = left; j < right; ++j ) {
                if( in[j] == pre[i] ) {
                    middle = j;
                    pre[i] = 0;
                    break;
                }
            }
            if( middle != -1 )
                break;
        }        
    }
    post += in[middle];
    getPost( middle + 1, right );
    getPost( left, middle );
    
}

int main() {
    
    while( cin >> pre >> in ) {
        post.erase();
        getPost( 0, pre.size() );
        int pos = pre.size();
        while( pos-- )
            putchar( post[pos] );
        putchar( '\n' ); 
    }

}
