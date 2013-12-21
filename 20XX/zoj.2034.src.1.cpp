// 3045139 2008-08-21 20:45:49 Accepted 2034 C++ 00:00.13 848K ���͵����� 

// ̰�ģ��ų���

// ������Ӳ��Ϊ�ٱҵı�Ҫ������

// 1. ��������ĳ�γ����б������
// 2. ��������ĳ���γ����зֱ����ػ�����
// 3. �����в����еĴ�������ƽ�����в��ȵĴ������

// ��ˣ���Υ������������һ���ߣ�������Ϊ�����

// ���ʣ�µľ��мٱҵ����ɣ����ʣ��һ�������ɣ����
// �����޷��б� 

#include <iostream>
#include <vector>
using namespace std;

int     A[1001],    B[1001];
bool    R[1001];

vector<int> X,  Y;

int     N,  Q,  T,  L; 

char    input;

int main() {
    
    for( cin >> T; T--; ) {
    
        cin >> N >> Q;
    
        memset( A, 0, sizeof( A ) );
        memset( B, 0, sizeof( B ) );
        memset( R, 0, sizeof( R ) );
        
        L = 0;
        
        while( Q-- ) {
            int K,  P;  cin >> K;
            X.clear();  Y.clear();
            for( int i = 0; i < K; ++i ) {
                cin >> P;
                if( !R[P] ) X.push_back( P );
            }
            for( int i = 0; i < K; ++i ) {
                cin >> P;
                if( !R[P] ) Y.push_back( P );
            }
            cin >> input;
            if( input == '=' ) {
                for( int i = 0; i < X.size(); ++i )
                    R[X[i]] = true;
                for( int i = 0; i < Y.size(); ++i )
                    R[Y[i]] = true;
            }
            else if( input == '<' ) {
                ++L;
                for( int i = 0; i < X.size(); ++i ) {
                    if( B[X[i]] )   R[X[i]] = true;
                    else    ++A[X[i]];
                }
                for( int i = 0; i < Y.size(); ++i ) {
                    if( A[Y[i]] )   R[Y[i]] = true;
                    else    ++B[Y[i]];
                }
            }
            else {
                ++L;
                for( int i = 0; i < X.size(); ++i ) {
                    if( A[X[i]] )   R[X[i]] = true;
                    else    ++B[X[i]];
                }
                for( int i = 0; i < Y.size(); ++i ) {
                    if( B[Y[i]] )   R[Y[i]] = true;
                    else    ++A[Y[i]];
                }
            }
        }

        vector<int> suspect( 0 ),   remain( 0 );
        
        for( int i = 1; i <= N; ++i ) {
            if( !R[i] ) remain.push_back( i );
            if( !R[i] && ( A[i] == L || B[i] == L ) )
                suspect.push_back( i );
        }
        
        if( remain.size() == 1 )
            cout << remain[0] << endl;
        else if( suspect.size() == 1 )
            cout << suspect[0] << endl;
        else    puts( "0" );

        if( T ) puts( "" );
    
    }
    
}
