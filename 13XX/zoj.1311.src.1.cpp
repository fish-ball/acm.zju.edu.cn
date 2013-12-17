// 2972159 2008-07-11 18:05:01 Accepted 1311 C++ 00:00.15 896K ���͵����� 

// ������ĸ��������˺þã���̫��ǳ��
// �������������ģ�����ĳ����ʱ���뵱Ȼ�ˣ��������棬�᱾��ĩ����ã���

// �����Ƶ����������� DFS ��Ȼ�Ѹ�ߵ�������˵�
// ���ڻ�ȥ��Ĺ��ʬ...Ψ�����...

// �����Ǹ���ʣ��������Ｄ���Լ�... 

/*                              �������
                                ��.��ӯ�� 

    һ�������֮���ھƼҡ��Ƽ�Ի����һ���ף�һ�������Ӷ���ˮ����κͣ�
�����գ���ɾơ������������������ˮ��������һ������κͣ����ն���֮��
��ˮҲ������ڽ�Ƽң�ν�������淨���Ƽ�Ի�������ڲ�ѭ�ҷ�Ҳ��������Ի��
����ѭ�������ö���ˮ��һ���������Ƽ�Ի����������ô�������˸���˼Ի��
�������������ף����� 
    �棡����֮������֮������ƣ����ڲ��þƣ�����ŭԹ��֮��֮��Ҳ��
��֮ѧ�ߣ�������ĩ����ѧ���ɣ��������ǣ� */

#include <sstream>
#include <string>
#include <iostream>
using namespace std;

bool    V[101][101]; 

int     N;

int     dph, cnt;   // DFS ���򣬸������ 
int     ord[101];   // ����ı����� 
int     low[101];   // ����������лر�ָ�������� 
int     pre[101];   // ����� DFS ������ 
int     tre[101];   // �������������� 
int     ans[101];   // �Ƿ��� 

void DFS( int v ) {
    
    low[v] = ord[v] = dph++;
    
    for( int w = 1; w <= N; ++w ) if( V[v][w] ) {
        
        // ���� 
        if( ord[w] == -1 ) {
            pre[w] = v;
            tre[v]++;
            DFS( w );
            if( low[v] > low[w] )
                low[v] = low[w];
            if( low[w] >= ord[v] )
                ans[v] = 1;
        }
        // �Ǹ��ߣ���Ϊ�ر߻��±� 
        else if( w != pre[v] ) {
            if( low[v] > ord[w] )
                low[v] = ord[w];
        }
    }
    
}


int main() {
    
    string  input;
    
    while( cin >> N && N ) {

        // ��ͼ 
        memset( V, 0, sizeof( V ) );
        
        int x,  y;
        
        while( cin >> x && x ) {
            getline( cin, input );
            istringstream   is( input );
            while( is >> y ) 
                V[x][y] = V[y][x] = true; 
        }
        
        // ��ʼ��
        dph = 0,    cnt = 0;
        memset( ord, -1, sizeof( ord ) );
        memset( low, -1, sizeof( low ) );
        memset( pre, -1, sizeof( pre ) );
        memset( tre,  0, sizeof( tre ) );
        memset( ans,  0, sizeof( ans ) );
        
        DFS( 1 );
        
        ans[1] = tre[1] > 1; 
        for( int i = 1; i <= N; ++i )
            cnt += ans[i];
        
        // ״̬���Ա�� 
        #ifndef ONLINE_JUDGE
        cout << "seq: ";for( int i = 1; i <= N; ++i ) printf( "%3d", i );       puts(""); 
        cout << "ord: ";for( int i = 1; i <= N; ++i ) printf( "%3d", ord[i] );  puts("");
        cout << "low: ";for( int i = 1; i <= N; ++i ) printf( "%3d", low[i] );  puts("");
        cout << "pre: ";for( int i = 1; i <= N; ++i ) printf( "%3d", pre[i] );  puts("");
        cout << "tre: ";for( int i = 1; i <= N; ++i ) printf( "%3d", tre[i] );  puts("");
        cout << "ans: ";for( int i = 1; i <= N; ++i ) printf( "%3d", ans[i] );  puts("");
        #endif 
        
        cout << cnt << endl; 

    }
    
}
