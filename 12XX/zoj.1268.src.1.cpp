// ����Ҫ̫����...
// �����ҵ��ĺܶ��㷨���ǳ���
// ��ʵ����������ÿ����һ���ߣ�����ָ��Ľڵ��� 
// ����Ѿ���ǹ��������� 
// ͬʱ��ǳ��ֹ��Ķ��������Լ����еı��� 
// ����ڱ�Ǳ�ָ����ʱ���Ѿ�������Ͳ����� 
// ���򣬵����������ڱ�����һ��ʱ������� 
// �벻��...��Ȼ������д��������߽��������� 
// �����鼯��û�õ���ʱ�� O(E)���ռ� 3 * O(V)

/*  Special Test Case

    Input:
        
    0 0
    -1 -1
    
    Output:
        
    Case 1 is a tree.
    
*/

// 2821991 2008-04-03 23:22:57 Accepted 1268 C++ 00:00.00 392K ���͵����� 

#include <cstdio>
#include <cstring>

int main() {
    bool    B[1001];
    bool    C[1001];
    int     v1, v2, T = 1;
    while( scanf( "%d%d", &v1, &v2 ) && ( v1 != -1 || v2 != -1 ) ) {
        memset( B, 0, sizeof( B ) );
        memset( C, 0, sizeof( C ) );
        bool    tree = true;
        // ��¼������������ 
        int     edge = 0,   vertex = 0;
        if( v1 || v2 ) while( 1 ) {
            if( tree ) {
                edge++;
                if( v1 == v2 )  tree == false;
                if( !B[v1] )    { vertex++; B[v1] = true; }
                if( !B[v2] )    { vertex++; B[v2] = true; }
                if( !C[v2] )    C[v2] = true;
                else            tree = false;
            }
            scanf( "%d%d", &v1, &v2 );
            if( !v1 && !v2 )    break;
        }
        tree = !edge || tree && vertex == edge + 1;
        printf( "Case %d is ", T++ );
        puts( tree ? "a tree." : "not a tree." );
    }
}
