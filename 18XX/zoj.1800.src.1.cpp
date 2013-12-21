// 2953653 2008-06-21 00:01:47 Accepted 1800 C++ 00:01.52 1236K ���͵����� 

// �ַ��� + ͼ + �׶�ʽ DP
// ����ע�� �ַ������� > L �������Ҫ��� 0 

// ���������Ĺ�ϵ�����һ����Ȩ����ͼ
// ��� �� j ���Խ��� �� i ���棬��ô��������� G[i][j]

// Ȼ�������ת��Ϊ�����ڳ���Ϊ L - X + 1 �Ĳ�ͬ��·���ж�����
// ���� L Ϊ���������X Ϊ��������
// ���ʱ���Ȳ鿴 L - X + 1 �ǲ��� > 0��������ǣ���� 0

// һ���� M ���� 
// Ȼ�󣬼�¼��ǰ�׶ε���� i ������·����ĿΪ C[i] 
// ��ֵΪ C[i] = 1 
// ÿ������ˢ��һ�£��ɳڣ����ظ� L - X �� 
//     ˢ�µİ취�ǣ��������� D[j] = 0����� C[i] != 0 �� G[i][j]
//     ����һ�� D[j] += C[i]������֮�� D ���ƻ� C
// ���C ����ͼ�Ϊ���

// �������ĸ��Ӷ�Ϊ��O(M * M * ( L - X ))�����Խ��� 

// ����ע��������ֻ��һ���ַ����������ʱ��ѡȡ�κ��ַ�������ν
// ���Ӧ���� pow(M, L) 

#include <iostream>
#include <string>
#include <algorithm>
#include <set> 
using namespace std;

int     N,  L,  M,  X;

bool    G[600][600];

int     C[600], D[600];

string  S[600]; 

int pw( int base, int ep ) {
    
    if( ep == 0 )
        return  1;
    
    int a = pw( base, ep >> 1 ); 
    
    if( ep & 1 )
        return  base * a * a;
        
    else
        return  a * a; 

} 

int main() {
    
    set<string> ss;
    set<string>::iterator iter; 
    
    while( cin >> N >> L >> M && N ) {
    
        // ����û˵�����������᲻���ظ���������Ϊ����
        // ʵ��֤��û�� 
        ss.clear(); 
        for( int i = 0; i < M; ++i )
            cin >> S[i];
        
        X = S[0].size(); 
        if( X == 1 ) { 
            cout << pw( M, L ) << endl;
            continue; 
        }
        
        // ����������ע�⣬�� WA �� 
        if( L < X ) {
            puts( "0" );
            continue;
        } 
        
        for( int i = 0; i < M; ++i )
            for( int j = 0; j < M; ++j )
                G[i][j] = S[i].substr(1) == S[j].substr(0, X-1);
        
        // ���������Ϣ������ɵ�����ͼ 
        #ifndef ONLINE_JUDGE 
        for( int i = 0; i < M; ++i ) {
            for( int j = 0; j < M; ++j )
                cout << G[i][j] << ' ';
            puts("");
        } 
        #endif 
        
        fill( C, C + M, 1 );
        for( int i = X; i < L; ++i ) {
            fill( D, D + M, 0 );
            for( int i = 0; i < M; ++i ) {
                if( C[i] ) for( int j = 0; j < M; ++j ) {
                    if( G[i][j] )
                        D[j] += C[i]; 
                }
            }
            copy( D, D + M, C ); 
        }
        
        int cnt = 0;
        
        for( int i = 0; i < M; ++i )
            cnt += C[i];
            
        cout << cnt << endl; 

    } 
    
} 
