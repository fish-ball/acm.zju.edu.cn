// 2893252 2008-05-06 15:35:22 Accepted 1149 C++ 00:00.01 848K ���͵����� 

// ʵ�����Ǹ�����������ֱ�Ӹ���̫����������
// �����һ�������������� 20�������������� 19��ż����� 20
// ԭ�����£�����ĳ�����Ӻܶ࣬������Ҫ��������ƽ����������ɵĲ�ƽ��
// ����ʵ�ʿ���Ҫ������ô��
// ���Ҹ��˾��ã�����ɵĲ�ƽ�⣬����� 20 �����ӻ�����������ô��Ъ���˰� 
// ���ǹ���... ˵�����ݵĴ������ǿ����ڸ��㷨��֤�Ĵ����Ե�... ym
 
// ������������ģ 30 ̫���ˣ������۸����ݣ��� 30 0 0 1 0 1 �����Ը�� 

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {

    set<int> S;
    set<int>::iterator  iter;
    vector<int> V;
    
    int A[7];
    
    for( int T = 1; ; ++T ) {
        
        for( int i = 1; i <= 6; ++i )
            cin >> A[i];
            
        if( !( A[1] || A[2] || A[3] ||
               A[4] || A[5] || A[6] ) ) break;
        
        cout << "Collection #" << T << ":\n";
        
        int sum = 0;
        for( int i = 1; i <= 6; ++i ) {
            if( A[i] > 20 )
                A[i] = A[i] % 2 ? 19 : 20;
            sum += A[i] * i;
        }
        
        if( sum % 2 ) {
            puts( "Can't be divided.\n" );
            continue;
        }
        
        sum /= 2;
        S.clear();
        S.insert( 0 );
        bool  div = false;

        for( int i = 6; i; --i ) {
            while( A[i]-- ) {
                V.clear();
                for( iter = S.begin(); iter != S.end(); ++iter ) {
                    if( *iter + i <= sum )
                        V.push_back( *iter + i );
                    if( *iter + i == sum ) {
                        div = true;
                        break;
                    }
                }
                if( div )   break;
                S.insert( V.begin(), V.end() );
            }
            if( div )   break;
        }
        
        puts( div ? "Can be divided.\n"
                  : "Can't be divided.\n" );
        
    }

}
